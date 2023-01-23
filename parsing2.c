/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:39:04 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/23 22:25:35 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_with_access(char **path, char *str)
{
	int		i;
	char	*join;

	i = 0;
	while (path[i] != NULL)
	{
		join = ft_strjoin(path[i], str);
		if (access(join, 0) != -1)
		{
			return (free(str), join);
		}
		i++;
		free(join);
		join = NULL;
	}
	return (free(join), free(str), NULL);
}

char	*backslash_case(char *av, int i)
{
	int		j;
	char	*join;

	j = 0;
	join = malloc(i + 1);
	while (av[j] != '\0')
	{
		join[j] = av[j];
		j++;
	}
	join[j] = '\0';
	return (join);
}

void	cmd2_redirect(int fd[2], char **c_p, char *av[], t_vars *vars)
{
	int		infile;
	int		outfile;

	infile = open(av[1], O_RDWR);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(infile);
	close(fd[0]);
	close(fd[1]);
	if (c_p[1])
	{
		if (execve(c_p[1], vars->splited_cmd2, 0) == -1)
			ft_printf("%s: command not found\n", av[3]);
	}
	free_tmp(c_p);
	free_strings(vars->splited_cmd1);
	free_strings(vars->splited_cmd2);
	exit(1);
}

void	close_pipe_files(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}
