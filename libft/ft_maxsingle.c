#include "libft.h"

int	ft_maxsingle(int *a, int size)
{
	int m;
	int i;

	i = 0;
	m = a[0];
	while (i < size)
	{
		m = (a[i] > m) ? a[i] : m;
		i++;
	}
	return (m);
}
