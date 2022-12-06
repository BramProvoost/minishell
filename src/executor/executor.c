/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:08:07 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/12/06 17:14:05 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "../main/main.h"
/* cmd's zijn in linked list -> execute op basis van: links, rechts, type, 
	eerste keer lezen van fd[1] - kan file zijn.
	check type - command/var/cd/pipe/&/>/>&/>>/>>&/</<</
	wachten op pid als het geen background is, anders asynchroon.
	output naar fd[1]
	lezen van fd[1]
	
	https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf

The strategy for your shell is to have the parent process do all the piping and redirection
before forking the processes. In this way the children will inherit the redirection. The parent
needs to save input/output and restore it at the end.


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

	
	niet: Not interpret unclosed quotes or special characters which are not required by the
	subject such as \ (backslash) or ; (semicolon).

Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash

// 4.1. read command table
// 4.x. creating pipes
// 4.x. creating processes

// execute commands op basis van wat het is. 
*/

void	execute_execve(t_line_lst *stack, t_data *data, char **envp)
{
	if (execve(data->path, data->cmd, envp) == -1)
		message_exit("execve went wrong", 0);
	exit(1);
	stack++;
}

void	execute_process(t_line_lst *stack, t_data *data, char **envp)
{
	pid_t	pid1;
	int	wstatus;

	redirect(stack, data);
	message(stack->value);

	pid1 = fork();
	if (pid1 < 0)
		message("fork went wrong");
	if (pid1 == 0)
	{
		//write(1, "child\n", 6);
		close(data->fd[0]);
		if (execve(data->path, data->cmd, envp) == -1)
			message_exit("execve went wrong", 0);
	}
	else
	{
		close(data->fd[1]);
		waitpid(pid1, &wstatus, 0);
		// if (WIFEXITED(wstatus))
		// 	message("proces einde\n");//, (WEXITSTATUS(wstatus)));
	}
	return ;
}

void	execute_commands(t_line_lst *stack, t_data *data, char **envp)
{
	if (!stack || !data)
		return ;
	data->cmd = ft_split(stack->value, ' ');
	// int i = -1;
	// while(data->cmd[++i])
	// 	message(data->cmd[i]);
	message_nl("value = ");
	message(data->cmd[0]);
	if (is_builtin(stack->value) == 1)
		execute_builtin(stack, data->cmd, data);
	else
	{
		data->path = get_cmd_path(data->cmd[0], envp);
		if (!data->path || !data->cmd[0])
			message("geen path of splitted cmd");
		if(stack)
		{
			// if (pipe(data->fd) < 0)
			// 	message("pipe werkt niet");
			data->outfile = data->fd[1];
			execute_process(stack, data, envp);
			close(data->outfile);
			if (data->infile != 0)
				close(data->infile);
			data->infile = data->fd[0];
			stack = stack->next;
		}
		if (data->cmd[0][0] == '\0')
			message_exit("cmd == '\0'", 1);
		if (ft_isspace(data->cmd[0][0]))
			exit(msg_custom_error_code("pipex: command not found: ", "", 0));
	}
}

// void	dup_all(t_data *data)
// {
	
// }
void	execute_cmd_list(t_line_lst *cmdlist, t_data *data)
{ t_line_lst *stack;
	
	if (!cmdlist)
		return ;
	stack = cmdlist;
	while(stack)
	{
		if (stack->next)
			pipe(data->fd);
		// ;
		//heredock checken
		execute_commands(stack, data, data->envp);
		if (data->fd[0] != 0)
			close(data->fd[0]);
		if (data->fd[1] != 1)
			close(data->fd[1]);
		data->infile = data->fd[0];
		stack = stack->next;	
	}
	message("end of stack");
}

void	test_lists(t_line_lst *head, char **envp)
{
	t_data	data;
	t_line_lst *cmdlist;
	char *str;

	data.envp = envp;
	str = NULL;
	while(head)
	{
		if (head->type == 0)
		{
			str = head->value;
			head = head->next;
		}
		while(head && head->type != 0)
		{
			str = ft_strjoin(str, " ");
			str = ft_strjoin(str, head->value);
			head = head->next;
		}
		add_at_end_of_list(&cmdlist, e_cmd, str);
	}
	execute_cmd_list(cmdlist, &data);

	// add_at_end_of_list(&head, e_word, "17");
	// add_at_end_of_list(&head, e_cmd, "grep gitignore");
	//add_at_end_of_list(&head, e_file, "outfile.txt");
	// show_t_list(head, "Put here the input line as reference");
	//printf("length of list is %d\n", length_of_list(head));
	//delete_list(&head);
	//show_list(head);
	//printf("length of list is %d\n", length_of_list(head));
}

