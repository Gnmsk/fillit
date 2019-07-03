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
	t_fgrs	**memory;
	int i;

	i = 5;
	if (ac < 2)
		return (-1);
	memory = file_valid(av[1]);
	solve_map(memory,i);
	return (0);
}

void	d_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	d_map(t_karta mapa)
{
	int i;

	i = 0;
	while (mapa.map[i])
	{
		ft_putendl(mapa.map[i++]);
	}
}
