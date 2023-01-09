#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char	*str;
	char *s;
	int pid;

	pid = fork();
	if (pid == 0)
	{
		int file = open("file1.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
		{
			printf("wrong");
			return (0);
		}
		int file2 = dup2(file, 1);
		printf("my name is tukka");
	}
}