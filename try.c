// #include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char	*str;
	char *s;
	int i;
	i = 0;
	printf("type ");
	scanf("%s", str);
	while (str[i] != '\0')
		i++;
	i = 0;
	s = malloc(i * sizeof(char));
	while(str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	printf("str = %s", s);
}