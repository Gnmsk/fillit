#include "libft.h"

int	ft_max(int *a, int *b, int size)
{
	int m;
	int k;

	m = a[0];
	k = 0;
	while (k < size)
	{
		m = (a[k] > m) ? a[k] : m;
		m = (b[k] > m) ? b[k] : m;
		k++;	
	}
	return (m);
}
