#include "fillit.h"

char **solve(t_fgrs memory)
{
	int i;
	t_fgrs	*temp;

	i = 0;
	map(temp[i] -> y[3])
	return ();
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
	while(y < i)
	{
		printf("%s",mapac[y]);
		printf("\n");
		y++;
	}
	return (map);
}
