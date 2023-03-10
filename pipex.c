/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:50:34 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/23 22:25:14 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char **env)
{
	char	*str;
	char	**tmp;
	char	**sub_path;

	str = NULL;
	tmp = malloc((3 * sizeof(char *)));
	sub_path = parsing_main_part(ac, av, env);
	if (!sub_path && (ft_strchr(av[2],'/') || ft_strchr(av[3],'/')))
	{
		tmp[0] = ft_strdup(av[2]);
		tmp[1] = ft_strdup(av[3]);
		tmp[2] = NULL;
		check_flags(av[2], av[3], tmp, av);
	}
	else if (sub_path != NULL)
	{
		tmp = checking_loop(sub_path, str, av, tmp);
		check_flags(av[2], av[3], tmp, av);
	}
	else
		return (free(tmp), free(sub_path), 0);
}

char	**checking_loop(char **sub_path, char *str, char *av[], char **tmp)
{
	int		i;
	int		j;

	i = 2;
	j = 0;
	while (i <= 3 && sub_path)
	{
		str = check_command_existence(av[i], sub_path);
		if (str == NULL)
		{
			ft_printf("%s: command not found\n", av[i]);
		}
		tmp[j] = ft_strdup(str);
		free(str);
		i++;
		j++;
	}
	tmp[j] = NULL;
	free_strings(sub_path);
	return (tmp);
}
