#include <stdio.h>
#include <unistd.h>
#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	valid_forms(char *str)
{
	int i;
	int q;

	i = 0;
	while (str[i])
	{
		q = 0;
		if (str[i] == '#')
		{
			if (i != 0)
				if (str[i - 1] == '#')
					q++;
			if (str[i + 1] == '#')
				q++;
			if (str[i + 5] == '#')
				q++;
			if (i > 4)
				if (str[i - 5] == '#')
					q++;
		}
		i++;
		if (q == 6 || q == 8)
			return (1);
	}
	return (0);
	
