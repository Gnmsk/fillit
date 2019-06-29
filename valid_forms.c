#include "fillit.h"

int	valid_forms(char *str)
{
	int i;
	int q;

	i = 0;
	q = 0;
	while (str[i])
	{
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
}

int      counter(char *s, int ch)
{
        int             nb;
        char    *str;

        nb = 0;
        str = (char *)s;
        while (*str)
        {
                if ((*str != '.') & (*str != '\n') & (*str != '#'))
                        return (-1);
                if (*str == ch)
                        nb++;
                str++;
        }
        return (nb);
}

char    **terms(int k, char *tmp)
{
        int             t;
        char    *tm;
        char    **terminos;

        t = 0;
        terminos = (char **)malloc(sizeof(char *) * (k / 21) + 1);
        tm = (char *)tmp;
        while (t < k / 21)
        {
                terminos[t] = ft_strncpy(ft_strnew(21), tm, 20);
                terminos[t][20] = '\0';
                printf("%s===\n", terminos[t]);
                tm = tm + 21;
                t++;
        }
        return (terminos);
}

int     terminos_check(char **str)
{
        int i;
        int a;

        i = 0;
        a = 0;
        while (str[i])
        {
                a += valid_forms(str[i]);
                i++;
        }
        return (a - i);
}
