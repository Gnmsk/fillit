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
	t_karta **mapa;

	if (ac < 2)
		return (-1);
	memory = file_valid(av[1]);
	mapa[0] = map(ft_max(memory[0]->x, memory[0]->y, 4));
	solve(memory, mapa);
	return (0);
}

void	d_error(void)
{
	ft_putendl("error");
	exit(0);
}

int	display_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i++]);
	}
	return (i);
}
