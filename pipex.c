/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:50:34 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/06 18:16:47 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// #include <stdio.h>
int	main(int ac, char *av[], char **env)
{
	char	*str;
	char	**sub_path;

	sub_path = parsing_main_part(ac, av, env);
	if (sub_path)
	{
		str = check_command_existence(av, sub_path);
		if (!str)
		{
			ft_printf("command not found: %s", av[2]);
			return (0);
		}
	}
	else
		return (0);
	// ft_printf("%s", str);
}
