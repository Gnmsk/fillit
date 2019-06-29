#include "fillit.h"

int	is_empty(t_karta *mapa, t_fgrs *temp)
{
	int i;

	i = 0;
	while (i++ <= 3)
	{
		if (mapa->map[temp->x[i]][temp->y[i]] != '.')
			return (0);
	}
	return (1);
}

void	putin(t_karta *mapa, t_fgrs *temp)
{
	int i;

	i = 0;
	while (i++ <= 4)
		mapa->map[temp->x[i]][temp->y[i]] = temp->letter;
}

t_karta map(int size, int i)
{
	t_karta	temp;
        char **map;
        int x;
        int y;

        y = 0;
	temp = (t_karta *)malloc(sizeof(t_karta));
        temp->map = (char **)malloc(sizeof(char *) * (size + 1));
        while (y < size)
        {
                temp->map[y] = (char *)malloc(sizeof(char) * (size + 1));
                x = 0;
		while (x < size)
		{
			temp->map[y][x] = '.';
			x++;
		}
		temp->map[y][x] = '\0';
                y++;
        }
	temp->map[y] = '\0';
	temp->id = i;
        return (temp);
}

char	**solve(t_fgrs **temp, t_karta **mapa)
{
	int i;
	char **mapka;

	i = 0;
	mapka = map(ft_max(temp[i]->x, temp[i]->y, 4));
	if (is_empty(mapka, temp[i]))
	{
		putin(mapka, temp[i]);
		i++;

	}
	else
		remap(&mapka);
	solve(temp[i]);
	return(NULL);
}

char	**remap(t_karta ***mapa)
{
	int i
	int j;
	char **newmap;

	i = 0;
	j = 0;
	while (*mapa[i])
		i++;
	newmap = map(i);
	while(j < i)
	{
		ft_strcpy(newmap[j] , *mapa[j]);
		j++;
	}
	return (newmap);
}
