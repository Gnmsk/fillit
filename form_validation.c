#include <stdio.h>
#include <unistd.h>
#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void	the_matrix(int form_code, int **matrix)
{
	int **temp;
	int i;
	int j;

	i = 0;
	j = 0;
	temp = matrix;

	while (temp[i])
	{
		if (temp[i] == form_code)
		{
			temp[i][j++];
			return (NULL);
		}
		i++;
	}
	temp[i] = form_code;
	temp[i][j++];
}

int	form_recognizer(char *str, int **matrix)
{
	int qnt;
	int i;
	int num;

	num = 0;
	qnt = ft_strlen(str) / 21;
	i = 0;
	while (str[i + 21] && num < qnt)
	{
		i = 21 * num;
		if (str[i] == '#')
		{
			if (str[i + 1] ==  str[i + 2])
			{
				if (str[i + 2] == str[i +3])
					the_matrix(123, &matrix);
				if (str[i + 2] == str[i +5])
                                        the_matrix(125, &matrix);
				if (str[i + 2] == str[i +6])
                                        the_matrix(126, &matrix);
				if (str[i + 2] == str[i +7])
                                        the_matrix(127, &matrix);
				else
					return (0);
			}
			if (str[i + 1] == '#' && str[i + 4] == '#' && str[i + 5] == '#')
				the_matrix(145, &matrix);
			if (str[i + 3] == '#' && str[i + 4] == '#' && str[i + 5] == '#')
				the_matrix(345, &matrix);
			if (str[i + 5] == '#' && str[i + 9] == '#' && str[i + 10] == '#')
				the_matrix(5910, &matrix);
			if (str[i + 1] == str[i + 5])
			{
				if (str[i + 5] == str[i +6])
                                        the_matrix(156, &matrix);
				if (str[i + 5] == str[i +10])
                                        the_matrix(1510, &matrix);
			}
			if (str[i + 1] == str[i + 6])
			{
				if (str[i + 6] == str[i + 7])
                                        the_matrix(167, &matrix);
				if (str[i + 6] == str[i + 11])
                                        the_matrix(16113, &matrix);
				else
					return (0);
			}
			if (str[i + 4] == str[i + 5])
			{
				if (str[i + 5] == str[i + 6])
                                        the_matrix(456, &matrix);
				if (str[i + 5] == str[i + 6])
                                        the_matrix(459, &matrix);
				if (str[i + 5] == str[i + 10])
                                        the_matrix(4510, &matrix);
				else
					return (0);
			}
			if (str[i + 5] == str[i + 6])
			{
				if (str[i + 6] == str[i + 7])
                                        the_matrix(567, &matrix);
				if (str[i + 6] == str[i + 10])
                                        the_matrix(5610, &matrix);
				if (str[i + 6] == str[i + 11])
                                        the_matrix(5611, &matrix);
				else
					return (0);
			}
			if (str[i + 5] == str[i + 10])
			{
				if (str[i + 10] == str[i + 11])
                                        the_matrix(51011, &matrix);
				if (str[i + 10] == str[i + 15])
                                        the_matrix(51015, &matrix);
				else
					return (0);
			}
			else
				return (0);
		}
		num++;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int fd;
	int i;
	int j;
	int matrix[19][2];
	char str[546];

	i = 0;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	read(fd, str, 546);
	form_recognizer(str, &matrix);
	while (matrix[i])
	{
		printf("%ls", matrix[i]);
		i++;
	}
	return (0);
}
