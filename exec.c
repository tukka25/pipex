/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:40:59 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/14 14:53:14 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parsing_main_part(int ac, char *av[], char **env)
{
	int		i;
	int		k;
	char	*s;
	char	**str;

	i = 0;
	k = 0;
	k = parsing(ac);
	if (k == 0)
		return (NULL);
	i = first_file_parsing(2, av);
	if (i == 0)
		return (NULL);
	i = second_file_parsing(5, av);
	if (i == 0)
		return (NULL);
	s = check_env_for_path(env);
	if (!s)
	{
		ft_printf("%s: No such file or directory\n", av[2]);
		ft_printf("%s: No such file or directory\n", av[3]);
		return (NULL);
	}
	str = ft_split(s, ':');
	return (str);
}

void	check_flags(char *cmd1, char *cmd2, char **cmd_path, char *av[], char **env)
{
	int		pid_cmd2;
	char	**splited_cmd1;
	char	**splited_cmd2;
	int		fd[2];
	int		pid_cmd1;

	splited_cmd1 = ft_split(cmd1, ' ');
	splited_cmd2 = ft_split(cmd2, ' ');
	int infile = open(av[1], O_RDWR);
	int outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipe(fd);
	if (infile == -1 || outfile == -1 || fd[0] == -1 || fd[1] == -1)
		exit (0);
	pid_cmd1 = fork();
	if (pid_cmd1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(infile, STDIN_FILENO);
		close(outfile);
		close(infile);
		close(fd[0]);
		close(fd[1]);
		if (execve(cmd_path[0], splited_cmd1, env) != -1)
		{
			free_strings(splited_cmd1);
			free_strings(splited_cmd2);
			perror("execve");
		}
		exit(1);
	}
	pid_cmd2 = fork();
	if (pid_cmd2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		close(infile);
		close(fd[0]);
		close(fd[1]);
		if (execve(cmd_path[1], splited_cmd2, env) != -1)
		{
			free_strings(splited_cmd1);
			free_strings(splited_cmd2);
			perror("execve");
		}
		exit(1);
	}
	close(infile);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_cmd1, NULL, 0);
	waitpid(pid_cmd2, NULL, 0);
	free_strings(splited_cmd2);
	free_strings(splited_cmd1);
}

void	free_strings(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	cmd1_redirection(int fd[2], char *cmd_path, char **env, char **splited_cmd1)
{
	int infile = open(av[1], O_RDWR);
	int outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	infile = open(av[1], O_RDWR);
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