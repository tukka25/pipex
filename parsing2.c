/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:40:59 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/09 16:01:29 by abdamoha         ###   ########.fr       */
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

char	*check_flags(char *av, char *cmd_path)
{
	int		i;
	char	**splited_cmd;
	// char	*join;
	int		file;
	int file2;
	// int		pid;

	i = 0;
	splited_cmd = ft_split(av, ' ');
	// ft_printf("s = %s", splited_cmd[1]);
	// pid = fork();
	// if (pid == 0)
	// {
		// printf("i\n");
		file = open("file1.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (0);
		// printf("i\n");
		// printf("i\n");
		file2 = dup2(file, STDOUT_FILENO);
		// printf("i\n");
		// while (splited_cmd[i] != NULL)
		// {
			// printf("i = %d", i);
			if (execve(cmd_path, splited_cmd, NULL) != -1)
				return (0);
				// i++;
				// printf("i = %d", i);
		// }
	// }
	// else{
	// 	sleep(1);
	// }
	return (NULL);
}

// int main(int ac, char *av[])
// {
// 	int		i;

// 	printf("s = %s\n", check_flags(av, )
// }
