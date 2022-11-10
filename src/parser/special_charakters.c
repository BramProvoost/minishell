/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   special_charakters.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 14:38:42 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/10 17:55:54 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	pipe_case(t_line_lst **line_lst)
{
	add_at_end_of_list(line_lst, e_pipe, "|");
}

int	less_than_case(t_line_lst **line_lst, char *line)
{
	if (line[1] == '<')
	{
		add_at_end_of_list(line_lst, e_delimiter, "<<");
		return (1);
	}
	add_at_end_of_list(line_lst, e_redirect_i, "<");
	return (0);
}

int	greater_than_case(t_line_lst **line_lst, char *line)
{
	if (line[1] == '>')
	{
		add_at_end_of_list(line_lst, e_append, ">>");
		return (1);
	}
	add_at_end_of_list(line_lst, e_redirect_o, ">");
	return (0);
}

int	dolar_special_case(t_line_lst **line_lst, char next_char)
{
	t_note	type;

	type = get_last_type(*line_lst);
	if (type == e_start || type == e_pipe)
		type = e_cmd;
	else
		type = e_var;
	if (next_char == '$')
		add_at_end_of_list(line_lst, type, "$$");
	if (next_char == '?')
		add_at_end_of_list(line_lst, type, "$?");
	return (1);
}

int	dolar_sign_case(t_line_lst **line_lst, char *line)
{
	t_note	type;

	type = get_last_type(*line_lst);
	if (type == e_start || type == e_pipe)
		type = e_cmd;
	else
		type = e_word;
	if (line[1] == '$')
		return (dolar_special_case(line_lst, '$'));
	if (line[1] == '?')
		return (dolar_special_case(line_lst, '?'));
	if (line[1] == ' ' || line[1] == '\0')
		add_at_end_of_list(line_lst, type, "$");
	return (0);
}
