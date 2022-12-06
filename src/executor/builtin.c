/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:36:37 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/11/25 17:16:08 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/* check testers voor alle builtins.
cd
echo
pwd
export
$?
exit
unset
SHLVL tot max 1000.
OLDPWD - als niet geset, set NULL
*/

int		is_builtin(char *str)
{
	int i;

	i = 0;
	if (!ft_strncmp(str, "cd", 2))
		i = 1;
	if (!ft_strncmp(str, "echo", 4))
		i = 1;
	if (!ft_strncmp(str, "pwd", 3))
		i = 1;
	if (!ft_strncmp(str, "export", 6))
		i = 1;
	if (!ft_strncmp(str, "$?", 2))
		i = 1;;
	if (!ft_strncmp(str, "unset", 5))
		i = 1;
	if (!ft_strncmp(str, "|", 1))
		i = 1;
	message(ft_itoa(i));
	return (i);
}

void	execute_builtin(t_line_lst *cmdlist, char **cmd, t_data *data)
{
	if (!cmdlist)
		return ;
	write(1, "builtin\n", 9);
	if (!ft_strncmp(cmdlist->value, "cd", 2))
		execute_cd(cmd, data);
	if (!ft_strncmp(cmdlist->value, "echo", 4))
		execute_echo(cmd);
	// if (!ft_strcmp(cmdlist->value, "pwd"))
	// 	execute_pwd(cmdlist);
	if (!ft_strncmp(cmdlist->value, "export", 6))
		execute_export(cmd, data);
	// if (!ft_strcmp(cmdlist->value, "$?"))
	// 	execute_exit_code(cmdlist);
	// if (!ft_strcmp(cmdlist->value, "unset"))
	// 	execute_unset(cmdlist, data);
}
