#include "fillit.h"

//char **solving(char ***map, t_fgrs ***temp, int size)
//{
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
//	return(NULL);
//}

int	checking(t_fgrs *memory, char	**tmp, int mapsize, int empty)
{
	int x;
	int y;
	int	i;

	i = 0;
	y = empty/mapsize;
	x = empty%mapsize;
	while(i < 4)
	{	
		if (tmp[y + memory->y[i]][x + memory->x[i]]  == '.')
			i++;
		else
			return (0);		
	}	
	return (1);
}

char	**put_in(t_fgrs *memory, char **tmp, int mapsize, int empty)
{
	int i;
	int x;
	int y;

	i = 0;
	y = empty/mapsize;
	x = empty%mapsize;
	while(i < 4)
	{
		tmp[y + memory->y[i]][x + memory->x[i]] = memory->letter;
		i++;
	}
	return (tmp);
}

char **solve(t_fgrs **memory)
{
	int mapsize;
	int t;
	int mp;
	t_map	*mapa;
//	int	figuresize;
	int empty;
	int check;

	t = 0;
	mp = 0;
       	mapsize = 16;	
	mapa = (t_map *)malloc(sizeof(t_map));
	mapa->current = map(mapsize);
	while (t < 6)
        {
	//	mapsize = 16;
	//	mapsize = ft_max(memory[t]-> x, memory[t]-> y, 4) + 1;
        //	mapa->current = map(mapsize);
        //	printf("\n");
                empty = 0;
		check = 0;
		while (empty < mapsize*mapsize && check < 1)
		{
			check = checking(memory[t], mapa->current, mapsize, empty);
			empty++; // in case of solving returns an error empty++
		}
	//	if (check == 0)
	//	{
//		}
		if (check == 1)
		{
			mapa->previous1 = mapa->previous;
			mapa->previous = mapa->current;
			mapa->current = put_in(memory[t], mapa->current, mapsize, empty-1);
		}
		mp = 0;
                while(mp < mapsize)
                {
                        printf("%s", mapa->current[mp]);
                        printf("\n");
                        mp++;
                }
                t++;
		printf("\n");
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
	y = 0;
//	while(y <= size)
//	{
//		printf("%s",map[y]);
//		printf("\n");
//		y++;
//	}
	return (map);
}
