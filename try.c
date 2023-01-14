#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char	*str;
	char *s;
	int pid;

		int f1 = open("file1.txt", O_WRONLY | O_CREAT, 0777);
	pid = fork();
	if (pid == 0)
	{
		if (file == -1)
		{
			printf("wrong");
			return (0);
		}
		int file2 = dup2(file, 1);
		printf("my name is tukka");
	}
}

void	first_cmd_exec(int fd[2], char **cmd_path, char *av[], char **env)
{
	int	infile;
	int	outfile;
	char
	
	splited_cmd1 = ft_split(cmd1, ' ');
	infile = open(av[1], O_RDWR);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd[1], STDOUT_FILENO);
		dup2(infile, STDIN_FILENO);
		close(outfile);
		close(infile);
		close(fd[0]);
		close(fd[1]);
		if (execve(cmd_path[0], splited_cmd1, env) != -1)
		{
			perror("execve");
		}
		exit(1);
}