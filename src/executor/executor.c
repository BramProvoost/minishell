/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:08:07 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/10/28 15:00:06 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/* cmd's zijn in linked list -> execute op basis van: links, rechts, type, 
	eerste keer lezen van fd[1] - kan file zijn.
	check type - command/var/cd/pipe/&/>/>&/>>/>>&/</<</
	wachten op pid als het geen background is, anders asynchroon.
	output naar fd[1]
	lezen van fd[1]
	
	https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf

*/

/*

The strategy for your shell is to have the parent process do all the piping and redirection
before forking the processes. In this way the children will inherit the redirection. The parent
needs to save input/output and restore it at the end.
*/

/*
	Have a working history
	Search and launch the right executable (based on the PATH variable or using a
	relative or an absolute path).
	Handle ’ (single quote) which should prevent the shell from interpreting the meta-
	characters in the quoted sequence.
	Handle " (double quote) which should prevent the shell from interpreting the meta-
	characters in the quoted sequence except for $ (dollar sign).
	
	""'$variabel'"" - testen
	
	<< should be given a delimiter, then read the input until a line containing the
	delimiter is seen. However, it doesn’t have to update the history!
	>> should redirect output in append mode
	environment variables ($variabele
	$? laatste exit code

	◦ echo with option -n : -nnnnnn -n -n -n -n -nnn == valid
	◦ cd with only a relative or absolute path
	◦ pwd with no options
	◦ export with no options
	◦ unset with no options
	◦ env with no options or argument
	◦ exit with no options
	met infile en outfile?
	SHLVL
	OLDPWD
	segfault = env checken als dingen leeg zijn.
	expand
	check of env leeg is.
	
	niet: Not interpret unclosed quotes or special characters which are not required by the
	subject such as \ (backslash) or ; (semicolon).
*/


// 4.1. read command table
// 4.x. creating pipes
// 4.x. creating processes

// execute commands op basis van wat het is. 
void	execute_process(t_line_lst *stack, t_data *data, char **envp)
{
	pid_t	pid1;
	int	wstatus;

	pid1 = fork();
	if (pid1 < 1)
		message_exit("fork went wrong", 0);
	if (pid1 == 0)
	{
		dup2(data->infile, 0);
		dup2(data->outfile, 1);
		if (execve(data->path, data->cmd, envp) == -1)
			message_exit("execve went wrong", 0);
	}
	else
	{
		close(data->fd[1]);
		waitpid(pid1, &wstatus, 0);
		if (WIFEXITED(wstatus))
			message_exit("process", (WEXITSTATUS(wstatus)));
	}
	message(stack->value);
}

void	execute_commands(t_line_lst *stack, t_data *data, char **envp)
{
	if (!stack || !data)
		return ;
	// if (stack->type == builtin)
	// 	execute_builtins(stack, data)
	// else if ()

	data->cmd = ft_split(stack->value, ' ');
	data->path = get_cmd_path(data->cmd[0], envp);
	if (!data->path || !data->cmd[0])
		message("geen path of splitted cmd");
	execute_process(stack, data, envp);
	if (data->cmd[0] == '\0')
		message_exit("cmd == '\0'", 1);
	if (ft_isspace(data->cmd[0][0]))
		exit(msg_custom_error_code("pipex: command not found: ", "", 0));
}

void	execute_cmd_list(t_line_lst *cmdlist, char **envp, t_data *data)
{
	t_line_lst *stack;

	int	stdinput;
	int	stdoutput;

	if (!cmdlist)
		return ;
	stack = cmdlist;
	//while niet last van stack.
	while(stack)
	{
		pipe(data->fd);
		stdinput = dup(0);
		stdoutput = dup(1);
		execute_commands(stack, data, envp);
		//close  &stdin, &stdout,
		stack = stack->next;
	}
}
