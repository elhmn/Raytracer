/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 19:41:08 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/02 19:42:17 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

# define BUFF_SIZE 8

/*
** read_file.c
*/

int			get_all(int fd, char **a);
char		*read_file(char *path);

#endif
