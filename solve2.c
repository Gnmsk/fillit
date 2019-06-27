#include "libft.h"

int	is_empty(char **map, t_fgrs *temp)
{
	int i;

	i = 0;
	while (i++ <= 3)
	{
		if (map[temp->x[i]][temp->y[i]] != '.')
			return (0);
	}
	return (1);
}

void	putin(char **map, t_fgrs *temp)
{
	int i;

	i = 0;
	while (i++ <= 4)
		map[temp->x[i]][temp->y[i]] = temp->letter;
}

char **map(int size)
{
        char **map;
        int x;
        int y;

        y = 0;
        map = (char **)malloc(sizeof(char *) * (size + 1));
        while (y < size)
        {
                map[y] = (char *)malloc(sizeof(char) * (size + 1);
                x = 0;
                while (x < size)
                {
                        map[y][x] = '.';
                        x++;
                }
		map[y][x] = '\0';
                y++;
        }
	map[y] = '\0';
        return (map);
}

char	solve(t_fgrs **temp)
{
	int i;
	char **mapka;

	i = 0;
	mapka = map(ft_max(*temp[i]->x, *temp[i]->y));
	if (is_empty(mapka, temp[i]))
	return();
}

char	**remap(char ***mapa)
{
	int i;
	char **newmap;

	i = 0;
	while (*mapa[i])
		i++;
	newmap = map(i);
}
