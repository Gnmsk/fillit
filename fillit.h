/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:28:47 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/13 18:59:55 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 546

# include "libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef	struct		s_fgrs
{
	int		x[4];
	int		y[4];
	char	letter;
}					t_fgrs;

typedef struct		s_karta
{
	char	**map;
	int		size;
}					t_karta;

int					valid_forms(char *str);
int					terminos_check(char **str, int k);
char				**terms(int k, char *tmp);
int					counter(char *s, int ch);
t_karta				map(int size);
t_fgrs				*shift(t_fgrs *temp);
t_fgrs				**coordinates(char **terminos, int k);
t_fgrs				**file_valid(char *file, int *i);
int					solve(t_fgrs **temp, t_karta *map, int n, int id);
char				**map_create(int size);
void				d_error(void);
void				d_map(char **map);
void				putin(t_fgrs *temp, t_karta *mapa, int xx, int yy);
void				putout(t_fgrs *temp, t_karta *mapa, int xx, int yy);
void				solve_map(t_fgrs **figuri, int n);
void				free_map(char ***map, int size);
int					is_empty(t_karta *mapa, t_fgrs *temp, int xx, int yy);

#endif
