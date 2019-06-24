#include "fillit.h"

char **solving(char ***map, t_fgrs ***temp, int size)
{
//	int i;
//	
//	i = 0;
//	while()
//	{
//		if(&map[x][y])
//		{
//			
//		}
//	}
	return(NULL);
}

char **solve(t_fgrs **memory)
{
	int i;
	int t;
	int mp;
	t_fgrs	**temp;
	t_map	*mapa;
	char 	**current;

	temp = memory;
	i = 0;
	t = 0;
	mp = 0;
	mapa = (t_map *)malloc(sizeof(t_map));
	mapa->current = map((ft_max(temp[t]-> x, temp[t]-> y, 4)) + i);
	while(mp <= ft_max(temp[t]-> x, temp[t]-> y, 4))
	{
		printf("%s", mapa->current[mp]);
		printf("\n");
		mp++;
	}
	return (0);
}

char **map(int size)
{
	char **map;
        int x;
        int y;
        char c = '.';

        y = 0;
        map = (char **)malloc(sizeof(char *) * size);
        while (y <= size)
        {
                map[y] = (char *)malloc(sizeof(char) * size);
                x = 0;
                while (x <= size)
                {
                        map[y][x] = c;
                        x++;
                }
                y++;
        }
	y = 0;
//	while(y <= size)
//	{
//		printf("%s",map[y]);
//		printf("\n");
//		y++;
//	}
	return (map);
}
