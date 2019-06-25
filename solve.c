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
//	yx = (int *)malloc(sizeof(int)*2);
//	yx[0] = -1;
//	yx[1] = -1;
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

char	**solving(t_fgrs **memory, t_map *mapa, int figuresize, int mapsize, int figurenumber)
{
	int	empty;
	t_fgrs 	**temp;
	int x;
	int y;
	int	i;

	i = 0;
	temp = memory;
	empty = searchempty(mapa, mapsize);
	y = empty/mapsize;
	x = empty%mapsize;
	//mapa->previous1 = mapa->previous;
        mapa->previous = mapa->current;
	if (y + ft_maxsingle(temp[figurenumber]->y, 4) > mapsize || x + ft_maxsingle(temp[figurenumber]->x, 4) > mapsize)
	      printf("error: map needs to be extended\n");
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
				printf("\ncell not empty\n");
				mapa->current = mapa->previous;
				return (NULL);
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
	while (t < 6)
        {
		figuresize = ft_max(temp[t]-> x, temp[t]-> y, 4);
        	mapa->current = map(figuresize+1);
                printf("\n\n");
                solving(temp, mapa, figuresize, figuresize+1, t);
                mp = 0;
                while(mp < figuresize+1)
                {
                        printf("%s", mapa->current[mp]);
                        printf("\n");
                        mp++;
                }
                t++;
        }
	t = 0;
	while (t < 6)
	{
		figuresize = ft_max(temp[t]-> x, temp[t]-> y, 4);
                mapa->current = map(mapsize);
		printf("\n\n");
		mapa->current[0][0] = 'z';
		mapa->current[0][3] = 'z';
		solving(temp, mapa, figuresize, mapsize, t);
		mp = 0;
		while(mp < mapsize)
		{
                	printf("%s", mapa->current[mp]);
                	printf("\n");
                	mp++;
        	}	
		t++;
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
