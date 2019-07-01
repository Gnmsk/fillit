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
	if (y + ft_maxsingle(memory->y, 4) >= mapsize || x + ft_maxsingle(memory->x, 4) >= mapsize)
		return (0);
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

char	**new_map(char **current, int mapsize)
{
	char	**tmp;
	int i;

	tmp = map(mapsize);
        i = 0;
	while (i < mapsize-1)
	{
		tmp[i] = ft_strncpy( tmp[i], current[i],  mapsize-1);
		tmp[i][mapsize-1] = '.';
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
	int empty;
	int check;

	t = 0;
	mp = 0;
       	mapsize = ft_max(memory[0]-> x, memory[0]-> y, 4) + 1;	
	mapa = (t_map *)malloc(sizeof(t_map));
	mapa->current = map(mapsize);
	while (memory[t])
        {
                empty = 0;
		check = 0;
		while (empty <= mapsize*mapsize && check < 1)
		{
			check = checking(memory[t], mapa->current, mapsize, empty);
			empty++; // in case of solving returns an error empty++
		}
		while (check == 0)
		{
			mapsize++;
			mapa->current = new_map(mapa->current, mapsize);
			empty = 0;
			while (empty < mapsize*mapsize && check < 1)
	                {
        	                check = checking(memory[t], mapa->current, mapsize, empty);
                	        empty++; // in case of solving returns an error empty++
                	}
		}
		if (check == 1)
		{
			mapa->previous1 = mapa->previous;
			mapa->previous = mapa->current;
			mapa->current = put_in(memory[t], mapa->current, mapsize, empty-1);
		}
		t++;
/*		mp = 0;
                while(mp < mapsize)
                {
			printf("%s\n", mapa->current[mp]);
			mp++;
                }
                t++;
		printf("\n");*/
        }
	mp = 0;
	while(mp < mapsize)
	{
		printf("%s\n", mapa->current[mp]);
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
