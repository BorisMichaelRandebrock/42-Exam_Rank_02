
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ok(char c)
{
	if (c > 32 && c < 127)
		return (1);
	return (0);
}

int	wc(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if ((i == 0 && ok(s[i])) || (ok(s[i]) && !ok(s[i - 1])))
			c++;
		i++;
	}
	return (c);
}
char	**ft_split(char *str)
{
	char	**res;
	int		words;
	int		w;
	int		i;
	int		j;
	int		start;
	int		end;

	i = 0;
	w = 0;
	words = wc(str);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		free(res);
	while (w < words)
	{
		if ((i == 0 && ok(str[i])) || (ok(str[i]) && !ok(str[i - 1])))
		{
			start = i;
			end = i;
			j = 0;
			while (ok(str[end]))
				end++;
			res[w] = (char *)malloc(sizeof(char) * ((end - start) + 1));
			while (start < end)
			{
				res[w][j] = str[start];
				start++;
				j++;
			}
			res[w][j] = '\0';
			w++;
		}
		i++;
	}
	res[words] = NULL;
	return (res);
}

int	main(int argc, char **argv)
{
	int		len;
	int		i;
	char	**res;

	i = 0;
	if (argc == 2)
	{
		len = wc(argv[1]) - 1;
		res = ft_split(argv[1]);
		while (len >= 0)
		{
			printf("%s", res[len]);// use ft_putstr... printf is forbidden!!!
			if (len >= 1)
				printf(" ");
			len--;
		}
		printf("\n");
	}
	return (0);
}
