/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:29:18 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/31 16:23:16 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing(int ac, char *av[])
{
	int	i;
	int	j;
	int d;

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
				// ft_printf("av[i] = %c\n", av[i][j]);
				if (!((av[i][j] >= 'a' && av[i][j] <= 'z') || (av[i][j] >= 'A' && av[i][j] <= 'Z')) && (av[i][j] != ' ' || av[i][j] != '\t'))
				{
					ft_printf("Error");
					d++;
					return (0);
				}
				j++;
			}
			// if (av[i][j] == '\0' && av[i][j + 1])
			// 	j++;
			i++;
		}
		// ft_printf("success");
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