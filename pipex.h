/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:21:26 by abdamoha          #+#    #+#             */
/*   Updated: 2023/01/14 23:03:35 by abdamoha         ###   ########.fr       */
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
# include <sys/wait.h>

typedef struct s_vars
{
	int		pid_cmd2;
	char	**splited_cmd1;
	char	**splited_cmd2;
	int		pid_cmd1;
}	t_vars;
int		ft_printf(const char *str, ...);
int		parsing(int ac, char *av[]);
int		first_file_parsing(int ac, char *av[]);
int		second_file_parsing(int ac, char *av[]);
char	*check_env_for_path(char **env);
char	*check_command_existence(char *av, char **env);
char	**parsing_main_part(int ac, char *av[], char **env);
void	check_flags(char *cmd1, char *cmd2, char **cmd_path, char *av[]);
void	free_strings(char **str);
char	**checking_loop(char **sub_path, char *str, char *av[], char **tmp);
char	*check_with_access(char **path, char *str);
void	cmd1_redirect(int fd[2], char **cmd_path, char *av[], char **splited_cmd1, char **splited_cmd2);
void	cmd2_redirect(int fd[2], char **cmd_path, char *av[], char **splited_cmd2, char **splited_cmd1);
void	free_tmp(char **tmp);
char	*backslash_case(char *av, int i);
#endif