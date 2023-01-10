/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:50:34 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/10 21:29:01 by abdamoha         ###   ########.fr       */
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
			str = check_command_existence(av[i], sub_path);
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
		tmp[j] = NULL;
		check_flags(av[2], av[3], tmp);
		free_strings(tmp);
		free_strings(sub_path);
	}
	else
		return (free(sub_path), 0);
}
