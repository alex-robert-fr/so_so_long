/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:17:16 by alrobert          #+#    #+#             */
/*   Updated: 2023/06/02 12:48:03 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "pacman.h"
#include "libft.h"
#include "ft_printf.h"

int	main(int argc, char *argv[])
{
	int	err;

	(void)argv;
	err = 0;
	if (argc == 2)
	{
		err = launch(argv[1]);
		if (err)
		{
			ft_printf("\033[5m\033[41mError\033[0m\033[25m\n");
			return (1);
		}
	}
	else
	{
		ft_printf("\033[41mLes arguments ne sont pas valide !\033[0m");
	}
	return (0);
}

int	launch(char *path_map)
{
	t_game	*game;
	int	checkf;

	(void)path_map;
	game = init_game();
	checkf = check_file(game, path_map);
	if (checkf == 1)
		ft_printf("%sBad parsing%s\n", RED, RST);
	if (checkf == 2)
		ft_printf("%sFile does not exist%s\n", RED, RST);
	if (checkf == 3)
		ft_printf("%sBad file format%s\n", RED, RST);

	return (0);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	return (game);
}
