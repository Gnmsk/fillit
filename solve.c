#include "filit.h"

char **solve(t_fgrs **memory)
{
	int i;
	t_fgrs	**temp;

	temp = memory;
	i = 0;
	map(ft_max(temp[i]-> y[3], temp[i]-> x[3]));
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
	while(y <= size)
	{
		printf("%s",map[y]);
		printf("\n");
		y++;
	}
	return (map);
}
