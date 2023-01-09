/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:50:34 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/10 02:46:45 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// #include <stdio.h>
int	main(int ac, char *av[], char **env)
{
	int		i;
	int		j;
	char	*str;
	char	**tmp;
	char	**sub_path;

	i = 2;
	j = 0;
	str = NULL;
	tmp = malloc((2 * sizeof(char *)) + 1);
	sub_path = parsing_main_part(ac, av, env);
	if (sub_path)
	{
		while (i <= 3 && sub_path)
		{
			// write (1, "Z", 1);
			str = check_command_existence(av[i], sub_path);
			// write (1, "D", 1);
			if (!str[j])
			{
				ft_printf("command not found: %s", av[i]);
				return (free(sub_path), 0);
			}
			tmp[j] = ft_strdup(str);
			free(str);
			i++;
			j++;
		}
		// ft_printf("j = %d", j);
		tmp[j] = NULL;
		i = 0;
		while (tmp[i] != NULL)
		{
			free(tmp[i]);
			i++;
		}
		free(tmp);
		i = 0;
		while (sub_path[i] != NULL)
		{
			free(sub_path[i]);
			i++;
		}
		free(sub_path);
		// printf("tmp = %s", *tmp);
		// check_flags(av[2], av[3], tmp);
	}
	else
		return (free(sub_path), 0);
}
