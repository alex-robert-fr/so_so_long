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
#include "get_next_line.h"
#include "map.h"
#include "vector.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	check_file(t_game *game, char *file_path)
{
	(void)game;
	if (check_path(file_path))
		return (1);
	check_map(file_path);
	return (0);
}

int	check_path(char *file_path)
{
	int	fd;
	int	err;

	err = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0))
		err = 1;
	else
		close(fd);
	return (err);
}

t_map	*check_map(char *file_path)
{
	char		*str;
	char		*next_str;
	t_map		*map;
	t_vector	size;
	t_check_map	checks;

	checks.fd = open(file_path, O_RDONLY);
	map = ft_calloc(sizeof(t_map), 1);
	str = gnl_trim(checks.fd, "\n");
	if (!str || !map)
		return ((void *)1);
	checks.err = 0;
	size = v_init(ft_strlen(str), 0);
	while (str)
	{
		#ifdef DEBUG
			ft_printf("=> %s\n", str);
		#endif
		next_str = gnl_trim(checks.fd, "\n");
		if (size.x != ft_strlen(str))
			checks.err = 1;
		size.y++;
		if (str)
			free(str);
		str = next_str;
	}
	close(checks.fd);
	if (checks.err)
	{
		free(map);
		return (NULL);
	}
	return (NULL);
}

char	*gnl_trim(int fd, char const *set)
{
	char	*str;
	char	*tmp_str;

	tmp_str = get_next_line(fd);
	if (!tmp_str)
		return (0);
	str = ft_strtrim(tmp_str, set);
	if (!str)
		return (0);
	if (tmp_str)
		free(tmp_str);
	return (str);
}
