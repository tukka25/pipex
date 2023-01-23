/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:40:59 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/23 22:23:11 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parsing_main_part(int ac, char *av[], char **env)
{
	int		i;
	char	*s;
	char	**str;

	i = 0;
	i = parsing(ac, av);
	if (i == 0)
		return (0);
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

void	check_flags(char *cmd1, char *cmd2, char **cmd_path, char *av[])
{
	t_vars	vars;
	int		infile;
	int		fd[2];
	int		outfile;

	vars.splited_cmd1 = ft_split(cmd1, ' ');
	// printf("spli = %s", vars.splited_cmd1[0]);
	vars.splited_cmd2 = ft_split(cmd2, ' ');
	infile = open(av[1], O_RDWR);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipe(fd);
	if (infile == -1 || outfile == -1 || fd[0] == -1 || fd[1] == -1)
		exit (0);
	vars.pid_cmd1 = fork();
	if (vars.pid_cmd1 == 0)
		cmd1_redirect(fd, cmd_path, av, &vars);
	vars.pid_cmd2 = fork();
	if (vars.pid_cmd2 == 0)
		cmd2_redirect(fd, cmd_path, av, &vars);
	close(fd[0]);
	close(fd[1]);
	waitpid(vars.pid_cmd1, NULL, 0);
	waitpid(vars.pid_cmd2, NULL, 0);
	free_tmp(cmd_path);
	free_strings(vars.splited_cmd2);
	free_strings(vars.splited_cmd1);
}

void	free_tmp(char **tmp)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
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

void	cmd1_redirect(int fd[2], char **c_p, char *av[], t_vars	*vars)
{
	int		infile;
	int		outfile;

	infile = open(av[1], O_RDWR);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(outfile);
	close(infile);
	close(fd[0]);
	close(fd[1]);
	// printf("c_p = %s\n", c_p[0]);
	if (c_p[0])
	{
		if (execve(c_p[0], vars->splited_cmd1, NULL) == -1)
			ft_printf("%s: command not found\n", av[2]);
	}
	free_tmp(c_p);
	free_strings(vars->splited_cmd1);
	free_strings(vars->splited_cmd2);
	exit(1);
}
