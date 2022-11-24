/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grammer_checker.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 11:23:56 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/24 16:24:57 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "grammer_checker.h"
#include <stdio.h>	// temp printf

int	is_valid_cmd(t_note last_type)
{
	if (last_type == e_start)
		return (1);
	if (last_type == e_pipe)
		return (1);
	return (0);
}

int	is_valid_pipe(t_note last_type)
{
	if (last_type == e_word)
		return (1);
	return (0);
}

int	is_valid_file(t_note last_type)
{
	if (last_type == e_redirect_i)
		return (1);
	if (last_type == e_redirect_o)
		return (1);
	if (last_type == e_delimiter)
		return (1);
	if (last_type == e_append)
		return (1);
	return (0);
}

int	is_valid_word(t_note last_type)
{
	if (last_type == e_cmd)
		return (1);
	if (last_type == e_word)
		return (1);
	if (last_type == e_var)
		return (1);
	return (0);
}

int	is_valid_var(t_note last_type)
{
	if (last_type == e_cmd)
		return (1);
	if (last_type == e_word)
		return (1);
	return (0);
}

int	is_valid_type(t_note type, t_line_lst *node)
{
	t_note	last_type;

	last_type = get_last_type(node);	// works only when bulding the list
	if (type == e_cmd)
		return (is_valid_cmd(last_type));
	if (type == e_file)
		return (is_valid_file(last_type));
	if (type == e_pipe)
		return (is_valid_pipe(last_type));
	if (type == e_word)
		return (is_valid_word(last_type));
	if (type == e_var)
		return (is_valid_var(last_type));
	return (0);
}

int	is_valid_grammer(t_line_lst *head)
{
	t_note	last_type;
	t_note	current_type;
	t_note	next_type;

	last_type = e_start;
	while (head != NULL)
	{
		current_type = head->type;
		if (head->next)
			next_type = head->next->type;
		else
			next_type = e_stop;
		printf("last %d\n", last_type);
		printf("current %d\n", current_type);
		printf("next %d\n", next_type);
		last_type = head->type;
		head = head->next;
	}
	return (1);
}
