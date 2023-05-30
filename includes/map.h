/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:18:40 by alrobert          #+#    #+#             */
/*   Updated: 2023/05/29 19:05:37 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
//# define DEBUG
# include "game.h"

typedef struct s_check_map
{
	int	fd;
	int	err;
}	t_check_map;

typedef struct s_map
{
	char	**map;
}	t_map;

int		check_path(char *file_path);
int		check_file(t_game *game, char *file_path);
char	*gnl_trim(int fd, char const *set);
t_map	*check_map(char *file_path);

#endif
