/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:24:24 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/13 18:48:36 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fgrs	*shift(t_fgrs *temp)
{
	t_fgrs	*t;

	t = temp;
	while (t->x[0] > 0 && t->x[1] > 0 && t->x[2] > 0 && t->x[3] > 0)
	{
		t->x[0] -= 1;
		t->x[1] -= 1;
		t->x[2] -= 1;
		t->x[3] -= 1;
	}
	while (t->y[0] > 0 && t->y[1] > 0 && t->y[2] > 0 && t->y[3] > 0)
	{
		t->y[0] -= 1;
		t->y[1] -= 1;
		t->y[2] -= 1;
		t->y[3] -= 1;
	}
	return (t);
}

t_fgrs	**coordinates(char **terminos, int k)
{
	int		t;
	int		i;
	int		j;
	t_fgrs	**lt;

	lt = (t_fgrs **)malloc(sizeof(t_fgrs) * k);
	t = 0;
	while (t < k)
	{
		lt[t] = (t_fgrs *)malloc(sizeof(t_fgrs));
		i = 0;
		j = 0;
		while (terminos[t][i])
			if (terminos[t][i++] == '#')
			{
				lt[t]->x[j] = i % 5;
				lt[t]->y[j] = i / 5;
				j++;
			}
		lt[t]->letter = (char)(t + 65);
		lt[t] = shift(lt[t]);
		t++;
	}
	free_map(&terminos, k);
	return (lt);
}
