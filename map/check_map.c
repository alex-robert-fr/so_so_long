/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:17:53 by alrobert          #+#    #+#             */
/*   Updated: 2023/05/29 17:23:08 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <fcntl.h>
#include <unistd.h>

int	check_file(t_game *game, char *file_path)
{
	(void)game;
	if (check_path(file_path))
		return (1);
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
	close(fd);
	return (err);
}
