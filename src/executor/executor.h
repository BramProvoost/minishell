/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:54:04 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/11/25 21:30:47 by dyeboa        ########   odam.nl         */
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
void	message_nl(char *msg);

//paths.c
char	*get_env_paths(char **envp);
char	*get_cmd_path(char *cmd, char **envp);

//redirect
void    redirect(t_line_lst *stack, t_data *data);

//file.c
void	open_infile(char *file);
void	redir_outfile(char *file, t_data *data, int flag);
void    redirect(t_line_lst *stack, t_data *data);

//builtin.c
void	execute_builtin(t_line_lst *cmdlist, char **cmd, t_data *data);
int		is_builtin(char *str);

//cd.c
void	execute_cd(char **cmd, t_data *data);
void	update_old_pwd(char *oldpath, t_data *data);
void	cd_home(char **envp);
int		change_dir(char *oldpath, char *path);

//echo.c
void	execute_echo(char **cmd);
int		check_option(char **cmd);

//export.c
void	execute_export(char **cmd, t_data *data);
int		check_env_exist(char **cmd, t_data *data);
#endif