/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:07:35 by tkelsie           #+#    #+#             */
/*   Updated: 2019/06/18 18:06:16 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	counter(char *s, int ch)
{
	int		nb;
	char	*str;

	nb = 0;
	str = (char *)s;
	while (*str)
	{
		if (*str != '.' & *str != '\n' & *str != '#')
			return (-1);
		if (*str == ch)
			nb++;
		str++;
	}
	return (nb);
}

int	main(int ac, char **av)
{
	int		fd;
	char	buffer[BUFF_SIZE];
	int		k;
	char	*tmp;

	fd = open(av[1], O_RDONLY);
	k = read(fd, &buffer, BUFF_SIZE);
	tmp = ft_strnew(k+1);
	tmp = ft_strncpy(tmp, buffer, k);
	tmp[k] = '\0';
	if (fd == -1 || k < 21 || k > 546 || k % 21 != 0 ||
	counter(tmp, '\n') % 5 != 0 || counter(tmp, '#') % 4 != 0 ||
	counter(tmp, '.') % 12 != 0)
	{
		write(1, "error\n", 6);
		return (-1);
	}
	return (0);
}
