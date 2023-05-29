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
#include <fcntl.h>
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
	int		fd;
	char	*str;
	t_map	*map;

	fd = open(file_path, O_RDONLY);
	map = ft_calloc(sizeof(t_map), 1);
	str	= get_next_line(fd);
	ft_printf("%s\n", str);
	if (!str || !map)
		return ((void*)1);
	(void)file_path;
	return (NULL);	
}
