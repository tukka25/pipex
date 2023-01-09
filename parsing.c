/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:29:18 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/09 17:10:53 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing(int ac)
{
	if (ac == 5)
		return (1);
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
}

int	first_file_parsing(int ac, char *av[])
{
	int	i;
	int	fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && av[1] != NULL)
	{
		if (fd == -1)
		{
			ft_printf("no such file or directory: %s", av[1]);
			return (0);
		}
		else if (fd > 0)
			return (1);
	}
	return (1);
}

int	second_file_parsing(int ac, char *av[])
{
	int	i;
	int	fd;

	i = 0;
	fd = open(av[4], O_RDONLY);
	if (ac == 5)
	{
		if (fd == -1)
		{
			ft_printf("no such file or directory: %s", av[4]);
			return (0);
		}
		else if (fd > 0)
			return (1);
	}
	return (1);
}

char	*check_env_for_path(char **env)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (&env[i][5]);
		i++;
	}
	return (NULL);
}

char	*check_command_existence(char *av, char **path)
{
	int		i;
	char	*str;
	char	*join;
	int		j;

	j = 0;
	i = ft_strlen(av);
	str = malloc(i + 2);
	str[0] = '/';
	i = 1;
	while (av[j] != '\0' && av[i - 1] != ' ')
	{
		str[i] = av[j];
		j++;
		i++;
	}
	str[i] = '\0';
	i = 0;
	while (path[i] != NULL)
	{
		join = ft_strjoin(path[i], str);
		if (access(join, 0) != -1)
			return (join);
		i++;
		free(join);
	}
	return (NULL);
}
