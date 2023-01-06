/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:40:59 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/06 18:17:05 by abdamoha         ###   ########.fr       */
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
		return (0);
	k = parsing(ac, av);
	if (k == 0)
		return (0);
	i = second_file_parsing(5, av);
	if (i == 0)
		return (0);
	s = check_env_for_path(env);
	if (!s)
		return (0);
	str = ft_split(s, ':');
	// printf("s = %s", *str);
	return (str);
}
