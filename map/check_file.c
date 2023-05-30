#include "game.h"
#include "map.h"
#include "libft.h"
#include "get_next_line.h"
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
