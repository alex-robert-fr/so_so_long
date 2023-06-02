/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:18:40 by alrobert          #+#    #+#             */
/*   Updated: 2023/06/02 11:55:05 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# define GREEN "\033[38;2;185;231;28m"
# define RED "\033[38;2;252;15;102m"
# define RST "\033[0m"
# include "game.h"
# include "vector.h"

//err 1 : Bad parsing
//err 2: Bad file format
typedef struct s_check_map
{
	int	fd;
	int	err;
	int	have_player;
	int	is_last;
}	t_check_map;

typedef struct s_map
{
	char		**map;
	t_vector	size;
}	t_map;

int			check_path(char *file_path);
int			check_file(t_game *game, char *file_path);
int			check_line(char *str, int len);
char		*gnl_trim(int fd, char const *set);
t_vector	initialize_size(char *str);
t_check_map	check_map(char *file_path);
t_check_map	initialize_checks(char *map_file);
t_check_map	process_line(char *str, t_vector *size, t_check_map checks);
t_check_map	finish_checking(t_check_map checks);

#endif
