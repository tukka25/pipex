/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:40:59 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/11 02:06:01 by abdamoha         ###   ########.fr       */
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
	i = first_file_parsing(2, av);
	if (i == 0)
		return (NULL);
	k = parsing(ac);
	if (k == 0)
		return (NULL);
	i = second_file_parsing(5, av);
	if (i == 0)
		return (NULL);
	s = check_env_for_path(env);
	if (!s)
		return (NULL);
	str = ft_split(s, ':');
	return (str);
}

char	*check_flags(char *cmd1, char *cmd2, char **cmd_path)
{
	int		pid_cmd2;
	char	**splited_cmd1;
	char	**splited_cmd2;
	int		fd[2];
	int		pid_cmd1;

	// i = 0;
	splited_cmd1 = ft_split(cmd1, ' ');
	splited_cmd2 = ft_split(cmd2, ' ');
	fd[1] = open("file1.txt", O_WRONLY | O_RDONLY | O_CREAT | O_TRUNC, 0777);
	fd[0] = open("outfile.txt", O_WRONLY | O_RDONLY | O_CREAT | O_TRUNC, 0777);
	pipe(fd);
	if (fd[1] == -1)
		return (0);
	pid_cmd1 = fork();
	if (pid_cmd1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (execve(cmd_path[0], splited_cmd1, NULL) != -1)
			return (0);
	}
	pid_cmd2 = fork();
	if (pid_cmd2 == 0)
	{
		// dup2(fd[0], STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		// sleep(3);
		if (execve(cmd_path[1], splited_cmd2, NULL) != -1)
			return (0);
	}
	close(fd[1]);
	close(fd[0]);
	waitpid(pid_cmd1, NULL, 0);
	waitpid(pid_cmd2, NULL, 0);
	return (NULL);
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
