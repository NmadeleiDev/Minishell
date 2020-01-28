/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:00:13 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/29 16:20:29 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_HEADER_H
# define SHELL_HEADER_H

# include "./ft_printf/includes/ft_printf.h"
# include "stdio.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_RESET "\x1b[0m"

char		*find_file(char **command, char **env_v);
char		*search_in_env(char *name, char *path);
int			read_comm(char **command);
char		*grep_str_from_arr(char **arr, char *str);
int			ft_cd(int num, char **argv, char **env_v);
void		sub_specials(char **command, char **env_v);
int			freesher(char **free_me);
void		ft_setenv(char **argv, char **env_v);
int			ft_unsetenv(char **argv, char **env_v);
void		set_shell(char option, char *name, char *val, char **env_v);
int			read_comm(char **command);
int			main();
int			freesher(char **free_me);
int			read_comm(char **command);
void		set_shell(char option, char *name, char *val, char **env_v);
char		**environ_holder(char option);
int			no_file(char **file, char *error);
char		*no_file_c(char **file, char *error);
char		**split_whitespaces(char *str);
void		*freeleak(char **arr);

#endif
