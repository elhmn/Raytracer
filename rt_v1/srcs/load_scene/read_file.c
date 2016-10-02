/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 19:40:06 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/02 19:45:16 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 19:10:36 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/02 19:37:55 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include "check_errors.h"
#include "read_file.h"

int			get_all(int fd, char **a)
{
	int		i;
	char	*buf;

	buf = ft_strnew(BUFF_SIZE);
	if (!buf)
		check_errors(MALLOC, "buf", "get_all.c");
	if (!a || fd < 0)
		return (0);
	if (!*a)
		*a = ft_strnew(1);
	while ((i = (int)read(fd, (void*)buf, (size_t)BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		*a = ft_realloc(*a, ft_strlen(*a), ft_strlen(*a) + i);
		ft_strcat(*a, buf);
	}
	free(buf);
	if (!*a || i < 0)
		return (0);
	return (1);
}

char	*read_file(char *path)
{
	int			fd;
	char		*str;

	fd = 0;
	str = NULL;
	if (path)
	{
		if ((fd = open(path, O_RDONLY)) == -1)
			perror("open");
		if (get_all(fd, &str) == 0)
			ft_putendl("error");
		close(fd);
	}
	return (str);
}
