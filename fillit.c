/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:07:35 by tkelsie           #+#    #+#             */
/*   Updated: 2019/06/22 16:03:40 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	int		fd;
	char	buffer[BUFF_SIZE];
	int		k;
	char	*tmp;
	char	**terminos;
	t_fgrs	**memory;

	if (ac < 2)
		return (-1);
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
	terminos = terms(k, tmp);
	if ((terminos_check(terminos)) != 0)
	{
		write(1, "error\n", 6);
                return (-1);	
	}
	memory = coordinates(terminos , k / 21);
	solve(memory);
	write(1, "success\n", 8);
	return (0);
}
