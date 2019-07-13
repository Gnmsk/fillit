/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:33:21 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/13 19:01:06 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_empty(t_karta *mapa, t_fgrs *temp, int xx, int yy)
{
	int i;

	i = 0;
	while (i <= 3)
	{
		if (mapa->map[temp->y[i] + yy][temp->x[i] + xx] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	putin(t_fgrs *temp, t_karta *mapa, int xx, int yy)
{
	int i;

	i = 0;
	while (i < 4)
	{
		mapa->map[temp->y[i] + yy][temp->x[i] + xx] = temp->letter;
		i++;
	}
}

void	putout(t_fgrs *temp, t_karta *mapa, int xx, int yy)
{
	int i;

	i = 0;
	while (i < 4)
	{
		mapa->map[temp->y[i] + yy][temp->x[i] + xx] = '.';
		i++;
	}
}

int		solve(t_fgrs **temp, t_karta *map, int n, int id)
{
	int xx;
	int yy;

	yy = 0;
	while ((yy + ft_maxsingle(temp[id]->y, 4)) < map->size)
	{
		xx = 0;
		while ((xx + ft_maxsingle(temp[id]->x, 4)) < map->size)
		{
			if (is_empty(map, temp[id], xx, yy))
			{
				putin(temp[id], map, xx, yy);
				if (id == n - 1 || solve(temp, map, n, id + 1))
					return (1);
				else
					putout(temp[id], map, xx, yy);
			}
			xx++;
		}
		yy++;
	}
	return (0);
}

void	solve_map(t_fgrs **figuri, int n)
{
	t_karta	*mapa;
	int		id;
	int		i;

	i = 1;
	id = 0;
	mapa = (t_karta *)malloc(sizeof(t_karta));
	mapa->size = i;
	mapa->map = map_create(mapa->size);
	while (!solve(figuri, mapa, n, id))
	{
		free_map(&mapa->map, mapa->size);
		mapa->size++;
		mapa->map = map_create(mapa->size);
	}
	d_map(mapa->map);
	free_map(&mapa->map, mapa->size);
	free(mapa);
	mapa = NULL;
}
