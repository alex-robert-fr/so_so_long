/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:17:53 by alrobert          #+#    #+#             */
/*   Updated: 2023/06/02 11:40:34 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "map.h"
#include "vector.h"
#include <fcntl.h>
#include <stdlib.h>

t_check_map	check_map(char *map_file)
{
	t_check_map	checks;
	char		*str;
	char		*next_str;
	t_vector	size;

	checks = initialize_checks(map_file);
	str = gnl_trim(checks.fd, "\n");
	if (!str)
		return (checks);
	size = initialize_size(str);
	while (str)
	{
		next_str = gnl_trim(checks.fd, "\n");
		if (!next_str)
			checks.is_last = 1;
		checks = process_line(str, &size, checks);
		if (checks.err)
			break ;
		str = next_str;
	}
	return (finish_checking(checks));
}

t_check_map	initialize_checks(char *map_file)
{
	t_check_map	checks;

	checks.err = 0;
	checks.have_player = 0;
	checks.fd = open(map_file, O_RDONLY);
	checks.is_last = 0;
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
	if (!check_line(str, size->x))
		checks.err = 1;
	size->y++;
	if (str)
		free(str);
	return (checks);
}

t_check_map	finish_checking(t_check_map checks)
{
	close(checks.fd);
	if (checks.err)
	{
		ft_printf("null");
		return (checks);
	}
	return (checks);
}
