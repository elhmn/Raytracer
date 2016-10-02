#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


char	*read_file(char *path);

int		main(int ac, char **av)
{
	int		ret;
	char	*str;
	char	*path;

	(void)ret;
	(void)str;
	(void)path;
	(void)ac;
	(void)av;

	if (ac == 2)
	{
		path = ft_strdup(av[1]);
		str = read_file(path);
		ft_putstr(str);

		free(str);
		free(path);
		while (42)(void)ac;
			ft_putendl("end Read"); //Debug
	}
}
