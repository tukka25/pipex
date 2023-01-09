/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:40:59 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/10 02:35:26 by abdamoha         ###   ########.fr       */
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
	// int		i;
	char	**splited_cmd1;
	char	**splited_cmd2;
	int		file1;
	// char	*str;
	int		pid;

	// i = 0;
	splited_cmd1 = ft_split(cmd1, ' ');
	// ft_printf("c2 = %s", cmd_path[0]);
	splited_cmd2 = ft_split(cmd2, ' ');
	file1 = open("file1.txt", O_WRONLY | O_RDONLY | O_CREAT, 0777);
	if (file1 == -1)
		return (0);
	pid = fork();
	if (pid == 0)
	{
		dup2(file1, STDOUT_FILENO);
		close(file1);
		if (execve(cmd_path[0], splited_cmd1, NULL) != -1)
			return (0);
	}
	else
	{
		close(file1);
		if (execve(cmd_path[1], splited_cmd2, NULL) != -1)
			return (0);
		sleep(1);
	}
	return (NULL);
}

// int main(int ac, char *av[])
// {
// 	int		i;

// 	printf("s = %s\n", check_flags(av, )
// }
