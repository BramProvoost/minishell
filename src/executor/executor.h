/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:54:04 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/11/24 16:24:34 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "../main/main.h"
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

typedef struct s_data
{
	char	**envp;
	char	**cmd;
	char	*path;
	int		infile;
	int		outfile;
	int		fd[2];

}	t_data;

//executor.c
void	execute_cmd_list(t_line_lst *cmdlist, t_data *data);
void	execute_commands(t_line_lst *stack, t_data *data, char **envp);
void	execute_process(t_line_lst *stack, t_data *data, char **envp);
void	close_fd_dup(t_data *data, int *stin, int *stout);
void	test_lists(t_line_lst *head, char **envp);

//errors.c
int		msg_error_code(char *err, int code);
int		msg_error(char *err);
int		msg_custom_error_code(char *err, char *cmd, int code);

//exit.c
void	message_exit(char *message, int errornumber);
void	message(char *msg);

//paths.c
char	*get_env_paths(char **envp);
char	*get_cmd_path(char *cmd, char **envp);

//redirect
void    redirect(t_line_lst *stack, t_data *data);

//file.c
void	open_infile(char *file, t_data *data);
void	open_till(char *file, t_data *data, char *str);
void	open_outfile(char *file, t_data *data, int flag);

#endif