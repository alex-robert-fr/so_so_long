/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:18:19 by alrobert          #+#    #+#             */
/*   Updated: 2023/05/29 16:18:59 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACMAN_H
# define PACMAN_H
# include "game.h"

int		launch(char *path_map);
t_game	*init_game(void);

#endif
