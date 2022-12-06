/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirect.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:36:37 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/11/03 13:58:05 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*

Implement redirections:
◦ < should redirect input.
◦ > should redirect output.
◦ << should be given a delimiter, then read the input until a line containing the
  delimiter is seen. However, it doesn’t have to update the history!
◦ >> should redirect output in append mode.

*/
#include "executor.h"

void	open_infile(char *file)
{
	int fd;

	if (!file)
		return ;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		message_exit("open_infile faalt", 1);
	dup2(fd, 0);
	close(fd);
}

void	redir_outfile(char *file, t_data *data, int flag)
{
	int fd;
	int flags;

	flags = 0;
	if (!file || data)
		return ;
	if (flag == e_redirect_o)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	else if (flag == e_append)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	fd = open(file, flags, 0644);
	if (fd < 0)
		message("red_outfile open");
	if (!dup2(fd, 1))
		message("open outfile dup");
	close(fd);
}
void    redirect(t_line_lst *stack, t_data *data)
{
    t_line_lst *temp;

    temp = stack;
    while(temp && temp->type != e_pipe )
    {
        if (temp->type == e_redirect_i)
            open_infile(temp->value);
        if (temp->type == e_redirect_o || temp->type == e_append)
            redir_outfile(temp->value , data, temp->type);
		temp = temp->next;
    }
	return ;
}