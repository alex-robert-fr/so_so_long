/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:50:07 by alex              #+#    #+#             */
/*   Updated: 2023/06/02 12:11:07 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	check_file(t_game *game, char *file_path)
{
	int			check_valid_file;
	t_check_map	is_valid;

	(void)game;
	check_valid_file = check_path(file_path);
	if (check_valid_file)
		return (check_valid_file);
	is_valid = check_map(file_path);
	if (is_valid.err)
		return (is_valid.err);
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
	if (ft_strcmp(file_path + ft_strlen(file_path) -  4, ".ber"))
		err = 2;
	else
		close(fd);
	return (err);
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
