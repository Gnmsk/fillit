#include "fillit.h"

char 	**map_build_c(int size)
{
	char **map;
	int x;
	int y;
	char c = '.';

	y = 0;
	map = (char **)malloc(sizeof(char *) * size);
	while (y < size)
	{
		map[y] = (char *)malloc(sizeof(char) * size);
		x = 0;
		while (x < size)
		{
			map[y][x] = c;
			x++;
		}
		y++;
	}
	return (map);
}

int	**map_build(int size)
{
	int **map;
	int x;
	int y;
	int i;

	y = 0;
	map = (int **)malloc(sizeof(int *) * (size));
	while (y < size)
	{
		map[y] = (int *)malloc(sizeof(int) * (size));
		i = 0;
		x = 0;
		while (x < size)
		{
			map[y][x] = i;
			x++;
			i++;
		}
		y++;
	}
	return (map);
}

int	main(int argc, char **argv)
{
	int i;
	int y;
	int x;

	int **mapa;
	char **mapac;
	y = 0;
	if (argc != 3)
	{
		printf("Enter 2 argvs, first - size, second 'c' or 'i' \n");
		return (0);
	}
	i = ft_atoi(argv[1]);
	if (argv[2][0] == 'i')
	{
		mapa = map_build(i);
		while(y < i)
		{
			x = 0;
			while (x < i)
			{
				printf("%d",mapa[y][x]);
				x++;
			}
			printf("\n");
			y++;
		}
	}
	if (argv[2][0] == 'c')
	{
		mapac = map_build_c(i);
		while(y < i)            
	       	{
			printf("%s",mapac[y]);
                        printf("\n");
                        y++;
                }

	}
	return (0);
}
