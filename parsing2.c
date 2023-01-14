/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:39:04 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/14 23:03:39 by abdamoha         ###   ########.fr       */
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
