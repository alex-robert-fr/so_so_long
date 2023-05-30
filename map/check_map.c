/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:17:53 by alrobert          #+#    #+#             */
/*   Updated: 2023/05/29 19:05:57 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "map.h"
#include "vector.h"
#include <fcntl.h>
#include <stdlib.h>

t_map	*check_map(char *map_file)
{
	t_check_map	checks;
	char		*str;
	char		*next_str;
	t_map		*map;
	t_vector	size;

	checks = initialize_checks(map_file);
	map = ft_calloc(sizeof(t_map), 1);
	str = gnl_trim(checks.fd, "\n");
	if (!str || !map)
		return (0);
	size = initialize_size(str);
	while (str)
	{
		next_str = gnl_trim(checks.fd, "\n");
		checks = process_line(str, &size, checks);
		str = next_str;
	}
	return (finish_checking(checks, map, size));
}

t_check_map	initialize_checks(char *map_file)
{
	t_check_map	checks;

	checks.err = 0;
	checks.have_player = 0;
	checks.fd = open(map_file, O_RDONLY);
	return (checks);
}

t_vector	initialize_size(char *str)
{
	t_vector	size;

	size = v_init(ft_strlen(str), 0);
	return (size);
}

t_check_map	process_line(char *str, t_vector *size, t_check_map checks)
{
	ft_printf("%s", str);
	size->y++;
	if (str)
		free(str);
	return (checks);
}

t_map	*finish_checking(t_check_map checks, t_map *map, t_vector size)
{
	close(checks.fd);
	if (checks.err || checks.have_player != 1)
	{
		free(map);
		return (NULL);
	}
	map->size = size;
	return (map);
}
