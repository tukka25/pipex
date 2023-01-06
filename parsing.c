/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:29:18 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/06 18:18:13 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing(int ac, char *av[])
{
	int	i;
	int	j;
	int	d;

	i = 2;
	j = 0;
	d = 0;
	if (ac == 5)
	{
		while (av[i] != NULL && i < 4)
		{
			j = 0;
			if (!av[i][j])
			{
				ft_printf("Error");
				return (0);
			}
			while (av[i][j] != '\0' && i < 4)
			{
				if (!((av[i][j] >= 'a' && av[i][j] <= 'z') || (av[i][j] >= 'A' && av[i][j] <= 'Z')) && (av[i][j] != ' ' || av[i][j] != '\t'))
				{
					ft_printf("Error");
					d++;
					return (0);
				}
				j++;
			}
			i++;
		}
		return (1);
	}
	else
	{
		ft_printf("Error");
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
		if (env[i][j] == 'P' && env[i][j + 1] == 'A' && env[i][j + 2] == 'T' && env[i][j + 3] == 'H')
			return (&env[i][5]);
		i++;
	}
	return (NULL);
}

char	*check_command_existence(char *av[], char **s)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = ft_strlen(av[2]);
	str = malloc(i + 2);
	str[0] = '/';
	i = 1;
	while (av[2][j] != '\0')
	{
		str[i] = av[2][j];
		j++;
		i++;
	}
	str[i] = '\0';
	// ft_printf("str11 = %s\n", str);
	i = 0;
	while (s[i] != NULL)
	{
		if (access(ft_strjoin(s[i], str), 0) != -1)
			return (s[i]);
		i++;
	}
	return (NULL);
}
