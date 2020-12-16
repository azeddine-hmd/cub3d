#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	printf("hello world\n");
	return (0);
}
