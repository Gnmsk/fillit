/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:35:58 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/13 19:09:23 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fgrs	**file_valid(char *file, int *i)
{
	int		fd;
	int		ret;
	char	buffer[BUFF_SIZE];
	char	**terminos;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		d_error();
	ret = read(fd, &buffer, BUFF_SIZE);
	buffer[ret] = '\n';
	buffer[ret + 1] = '\0';
	if (counter(buffer, '#') % 4 != 0 || counter(buffer, '.') % 12 != 0
	|| ret < 20 || (ret + 1) % 21 > 0 || counter(buffer, '.') == 0
	|| (counter(buffer, '\n')) % 5 != 0)
		d_error();
	terminos = terms(ret + 1, buffer);
	if (terminos_check(terminos, (ret + 1) / 21) != 0)
	{
		free_map(&terminos, (ret + 1) / 21);
		d_error();
	}
	*i = (ret + 1) / 21;
	return (coordinates(terminos, (ret + 1) / 21));
}

int		valid_forms(char *str)
{
	int i;
	int q;

	i = 0;
	q = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i != 0)
				if (str[i - 1] == '#')
					q++;
			if (str[i + 1] == '#')
				q++;
			if (str[i + 5] == '#')
				q++;
			if (i > 4)
				if (str[i - 5] == '#')
					q++;
		}
		i++;
		if (q == 6 || q == 8)
			return (1);
	}
	return (0);
}

int		counter(char *s, int ch)
{
	int		nb;
	char	*str;

	nb = 0;
	str = (char *)s;
	while (*str != '\0')
	{
		if ((*str != '.') & (*str != '\n') & (*str != '#'))
			return (-1);
		if (*str == ch)
			nb++;
		str++;
	}
	return (nb);
}

char	**terms(int k, char *tmp)
{
	int		t;
	char	**terminos;

	t = 0;
	terminos = (char **)malloc(sizeof(char *) * (k / 21) + 1);
	while (t < k / 21)
	{
		terminos[t] = ft_strncpy(ft_strnew(21), tmp, 20);
		terminos[t][20] = '\0';
		tmp = tmp + 21;
		t++;
	}
	terminos[t] = NULL;
	return (terminos);
}

int		terminos_check(char **str, int k)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (i < k)
	{
		if (str[i][4] != '\n' || str[i][9] != '\n' ||
		str[i][14] != '\n' || counter(str[i], '\n') % 4 != 0)
			d_error();
		a += valid_forms(str[i]);
		i++;
	}
	return (a - i);
}
