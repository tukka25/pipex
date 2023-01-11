/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:21:26 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/11 04:18:14 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
#include <sys/wait.h>

int		ft_printf(const char *str, ...);
int		parsing(int ac);
int		first_file_parsing(int ac, char *av[]);
int		second_file_parsing(int ac, char *av[]);
char	*check_env_for_path(char **env);
char	*check_command_existence(char *av, char **env);
char	**parsing_main_part(int ac, char *av[], char **env);
void	check_flags(char *cmd1, char *cmd2, char **cmd_path);
void	free_strings(char **str);
#endif