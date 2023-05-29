#include "pacman.h"
#include "libft.h"
#include "ft_printf.h"

int	main(int argc, char *argv[])
{
	(void)argv;
	int	err;

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
	t_game	*init;
	(void)path_map;

	init = init_game();
	return (0);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	return (game);
}

