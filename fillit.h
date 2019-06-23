/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:28:47 by tkelsie           #+#    #+#             */
/*   Updated: 2019/06/18 18:02:07 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 547

# include "libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct		s_fgrs
{
	int	x[4];
	int	y[4];
	char	letter;
}			t_fgrs;

int     valid_forms(char *str);
int     **coordinates(char **str, int k);
int     terminos_check(char **str);
char    **terms(int k, char *tmp);
int      counter(char *s, int ch);
t_fgrs	*shift(t_fgrs *temp);
//int     *shift(int *temp);
int     **coordinates(char **terminos, int k);

#endif
