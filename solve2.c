#include "fillit.h"

int	is_empty(t_karta mapa, t_fgrs temp, int xx, int yy)
{
	int i;

	i = 0;
	while (i++ <= 3)
	{
		if (mapa.map[temp.x[i] + xx][temp.y[i] + yy] != '.')
			return (0);
	}
	return (1);
}

void	putin(t_fgrs temp, t_karta mapa, int xx, int yy)
{
	int i;

	i = 0;
	while (i++ <= 4)
		mapa.map[temp.x[i] + xx][temp.y[i] + yy] = temp.letter;
}

void	putout(t_fgrs temp, t_karta mapa, int xx, int yy)
{
	int i;

        i = 0;
        while (i++ <= 4)
                mapa.map[temp.x[i] + xx][temp.y[i] + yy] = '.';
}

char	**map_create(int size)
{
        char **map;
        int x;
        int y;

        y = 0;
        map = (char **)malloc(sizeof(char *) * (size + 1));
        while (y < size)
        {
                map[y] = (char *)malloc(sizeof(char) * (size + 1));
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

void	free_map(char ***map, int size)
{
	while (size--)
	{
		free(map[0][size]);
		map[0][size] = NULL;
	}
	free(map[0]);
	map[0] = NULL;
}

int    solve(t_fgrs temp[], t_karta map, int n, int id)
{
        int xx;
	int yy;

	yy = 0;
	while ((yy + ft_maxsingle(temp[id].y, 4)) <= map.size)
	{
		xx = 0;
		while((xx + ft_maxsingle(temp[id].x, 4)) <= map.size)
		{
			if(is_empty(map, temp[id], xx, yy))
			{
				putin(temp[id], map, xx, yy);
				if (id == n - 1 || solve(temp, map, n, id + 1))
					return (1);
				else
					putout(temp[id], map, xx, yy);
			}
			xx++;
		}
		yy++;
	}
	return (0);
}

void	solve_map(t_fgrs *figuri[], int n)
{
	t_karta mapa;
	int id;

	id = 0;
	mapa.size = n;
	mapa.map = map_create(mapa.size);
	while (!solve(figuri, mapa, n, id))
	{
		free_map(&mapa.map, mapa.size);
		mapa.size++;
		mapa.map = map_create(mapa.size);
	}
	d_map(mapa);
	free_map(&mapa.map, mapa.size);
}
