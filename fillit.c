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

	if (ac < 2)
		return (-1);
	memory = file_valid(av[1]);
	solve(memory);
	return (0);
}

void	d_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}
