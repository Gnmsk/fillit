#include "fillit.h"

int	*shift(int *temp)
{
	int *t;

	t = temp;
	while (t[1] > 0 && t[3] > 0 && t[5] > 0 && t[7] > 0)
	{
		t[1]-= 1;
		t[3]-= 1;
		t[5]-= 1;
		t[7]-= 1;
	}
	while (t[0] > 0 && t[2] > 0 && t[4] > 0 && t[6] > 0)
	{
		t[0]-= 1;
                t[2]-= 1;
                t[4]-= 1;
                t[6]-= 1;
	}
	return (t);
}

int     **coordinates(char **terminos, int k)
{
        int t;
        int     **temp;
        int i;
        int j;
	int s;
	int pp;

        t = 0;
        temp = (int **)malloc(sizeof(int *) * k + 1);
        while (t < k)
        {
                temp[t] = (int *)malloc(sizeof(int) * 8 + 1);
                i = 0;
                j = 0;
		s = 0;
                while (terminos[t][i])
                {
                        if (terminos[t][i] == '#')
                        {
                                temp[t][j + 1] = i % 5;
                                temp[t][j] = i / 5;
				printf("%d %d ", temp[t][j], temp[t][j+1]);
                                j += 2;
                        }
                        i++;
                }
		temp[t] = shift(temp[t]);
		pp = 0;
		while (pp < 8)
		{
			printf("%d ", temp[t][pp]);
			pp++;
		}
		t++;
		printf("\n\n");

        }
        return (temp);
}
