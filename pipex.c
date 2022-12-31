/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:50:34 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/31 16:31:59 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// #include <stdio.h>
int	main(int ac, char *av[])
{
	int i = 0;
	// int k = 0;
	ac = 0;
	*av = NULL;
	// i = first_file_parsing(2, av);
	// if (i == 0)
	// 	return (0);
	// k = parsing(ac, av);
	// if (k == 0)
	// 	return (0);
	// i = second_file_parsing(5, av);
	// if (i == 0)
	// 	return (0);
	i = fork();
	if (i != 0)
		fork();
	ft_printf("tukka = %d\n", i);
	return (0);
	// parsing(ac, av);
	
}
