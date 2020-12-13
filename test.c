#include <stdio.h>

void	ft_strlen(const char *s)
{
	int i;

	i = -1;
	while (s[i])
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	printf("Hello World\n");
	return (0);
}
