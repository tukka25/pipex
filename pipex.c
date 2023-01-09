/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:50:34 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/09 21:10:34 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// #include <stdio.h>
int	main(int ac, char *av[], char **env)
{
	int		i;
	int		j;
	char	*str;
	char	**sub_path;

	i = 2;
	j = 0;
	// printf("av = %s", av[2]);
	// check_flags("ls ", "/bin/ls");
	// exit(0);
	sub_path = parsing_main_part(ac, av, env);
	if (sub_path)
	{
		while (i <= 3 && sub_path)
		{
			str = check_command_existence(av[i], sub_path);
			if (!str)
			{
				ft_printf("command not found: %s", av[i]);
				return (0);
			}
			i++;
			j++;
		}
		check_flags(av[2], av[3], str, sub_path);
	}
	else
		return (0);
}
