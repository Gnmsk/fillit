/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:07:35 by tkelsie           #+#    #+#             */
/*   Updated: 2019/06/18 14:37:53 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*reading(int ac, char *av)
{
	int		fd;
	char	buffer[BUFF_SIZE];

	fd = open(av[1], O_RDONLY);
	if (fd == -1 || read(fd, buffer, BUFF_SIZE) < 0 || ac > 2)
		return (-1);
	buffer[BUFF_SIZE] = '\0';
	return (NULL);
}

char	*fillit(char *str)
{
	return (NULL);
}
