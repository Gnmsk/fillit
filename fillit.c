/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:07:35 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/10 15:55:53 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**map_create(int size)
{
	char	**map;
	int		x;
	int		y;

	y = 0;
	map = (char **)malloc(sizeof(char *) * (size)/* + 1*/);
	/*map[size] = NULL;*/
	while (y < size)
	{
		map[y] = (char *)malloc(sizeof(char) * (size + 1));
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	return (map);
}

void	free_map(char **map, int size)
{
	size = 0;
	while (map[size])
	{
		free(map[size]);
	//	map[0][size] = NULL;
	size++;
	}
//	free(map[size]);
	free((void*)map);
//	map[0] = NULL;
}

int		main(int ac, char **av)
{
	t_fgrs	**memory;
	int		i;

	if (ac != 2)
	{
		ft_putendl("Usage: put one file");
		return (-1);
	}
	memory = file_valid(av[1], &i);
	solve_map(memory, i);
	i--;
	free_mem(memory, i);
	return (0);
}

void	d_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	d_map(t_karta *mapa)
{
	int i;

	i = 0;
	while (mapa->map[i])
	{
		ft_putendl(mapa->map[i]);
		i++;
	}
}
