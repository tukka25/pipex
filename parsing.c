/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:29:18 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/23 19:33:34 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing(int ac, char *av[])
{
	if (ac == 5)
	{
		if (av[2][0] == '\0' || av[3][0] == '\0')
		{
			return (1);
		}
		return (1);
	}
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
}

int	first_file_parsing(int ac, char *av[])
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		perror("open");
	close (fd);
	if (ac == 2 && av[1] != NULL)
	{
		if (fd == -1)
		{
			ft_printf("%s: No such file or directory\n", av[1]);
			return (0);
		}
		else if (fd > 0)
			return (1);
	}
	return (1);
}

int	second_file_parsing(int ac, char *av[])
{
	int	fd;

	fd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	close(fd);
	if (ac == 5)
	{
		if (fd == -1)
		{
			ft_printf("%s: No such file or directory\n", av[4]);
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
	if (ft_strchr(av, '/') != NULL)
	{
		return (backslash_case(av, i));
	}
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
	join = check_with_access(path, str);
	return (join);
}
