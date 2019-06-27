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

int	searchempty(t_map *mapa, int size)
{
	int c;
	int yx;

	yx = -1;
	c = 0;
	printf("mapsize %d \n", size);
	while (c < size*size && yx == -1)
	{
		if (mapa->current[c/size][c%size] == '.')
		{	yx = c;
			printf("empty cell: %d %d\n\n", yx/size, yx%size);
			return(yx);
		}
		c++;
	}
	printf("\n%d %d\n", yx/size, yx%size);
	return (yx);
}

char	*solving(t_fgrs **memory, t_map *mapa, int mapsize, int figurenumber, int empty)
{
	t_fgrs 	**temp;
	int x;
	int y;
	int	i;

	i = 0;
	temp = memory;
	y = empty/mapsize;
	x = empty%mapsize;
	//mapa->previous1 = mapa->previous;
        mapa->previous = mapa->current;
	if (y + ft_maxsingle(temp[figurenumber]->y, 4) > mapsize || x + ft_maxsingle(temp[figurenumber]->x, 4) > mapsize)
	{
		printf("map needs to be extended\n");
		return("error: map needs to be extended\n");
	}
	// draw new map
	else
	{
		while(i < 4)
		{	
			if ( mapa->current[y + temp[figurenumber]->y[i]][x + temp[figurenumber]->x[i]]  == '.')
			{
				mapa->current[y + temp[figurenumber]->y[i]][x + temp[figurenumber]->x[i]] = temp[figurenumber]->letter;
				i++;
			}
			else
			{
				printf("cell not empty\n");
				mapa->current = mapa->previous;
				return ("error");
			}
		}		
	}
	mapa->previous1 = mapa->previous;	
	return (NULL);
}

char **solve(t_fgrs **memory)
{
	int mapsize;
	int t;
	int mp;
	t_fgrs	**temp;
	t_map	*mapa;
	int	figuresize;
	int empty;

	empty = 0;
	temp = memory;
	t = 0;
	mp = 0;
	figuresize = ft_max(temp[t]-> x, temp[t]-> y, 4);
       	mapsize = 4;	
	mapa = (t_map *)malloc(sizeof(t_map));
	mapa->current = map(mapsize);
	while(mp < mapsize)
	{
		printf("%s", mapa->current[mp]);
		printf("\n");
		mp++;
	}
	while (t < 6) //добить нулевую структуру для вайла
        {
		figuresize = ft_max(temp[t]-> x, temp[t]-> y, 4);
        	mapa->current = map(figuresize+1);              //в мап закинуть функцию фт макс
                printf("\n");
                empty = searchempty(mapa, figuresize+1);
		while (empty < mapsize*mapsize && solving(temp, mapa, figuresize+1, t, empty) != NULL)
			empty++; // in case of solving returns an error empty++
		//solving(temp, mapa, figuresize+1, t, empty);
                mp = 0;
                while(mp < figuresize+1)
                {
                        printf("%s", mapa->current[mp]);
                        printf("\n");
                        mp++;
                }
                t++;
		printf("\n");
        }
	t = 0;
	while (t < 6)
	{
		figuresize = ft_max(temp[t]-> x, temp[t]-> y, 4);
                mapa->current = map(mapsize);
		printf("\n");
		mapa->current[0][0] = 'z';
		mapa->current[0][3] = 'z';
		empty = searchempty(mapa, mapsize);
		//solving(temp, mapa, mapsize, t, empty);
		while (empty < mapsize*mapsize && solving(temp, mapa, figuresize+1, t, empty) != NULL)
		{
			empty++; // in case of solving returns an error empty++
			printf("new attempt\n");
		}
		// if (empty == mapsize*mapsize)
		// 	draw new map
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

// tried to solve all the maps

	mapa->current = map(16);
	mapa->current[0][0] = 'z';
	t = 0;
	while (t < 6)
        {
                figuresize = ft_max(temp[t]-> x, temp[t]-> y, 4);
                empty = searchempty(mapa, 16);
                while (empty < 16*16 && solving(temp, mapa, 16, t, empty) != NULL)
                {
                        empty++; // in case of solving returns an error empty++ and also it doesn't delete previous solution right now
                        printf("new attempt\n");
                }
                // if (empty == mapsize*mapsize)
                //      draw new map
                t++;
        }
	mp = 0;
	while(mp < 16)
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
