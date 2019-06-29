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

t_karta *map(int size)
{
	t_karta	*temp;
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
	temp->id = 0;
        return (temp);
}

char	**solve(t_fgrs **temp, t_karta **mapa)
{
	int i;
	int id;

	i = 0;
	id = 0;
	if (is_empty(mapa, temp[i]))
	{
		putin(mapa, temp[i]);
		i++;

	}
	else
		remap(&mapa);
	solve(temp[i], mapa);
	return(NULL);
}

t_karta **remap(t_karta ***mapa)
{
	int i;
	int j;
	t_karta *newmap;

	i = 0;
	j = 0;
	while (*mapa->map[i])
		i++;
	newmap = map(i);
	while(j < i)
	{
		ft_strcpy(newmap->map[j] , mapa->map[j]);
		j++;
	}
	return (newmap);
}
