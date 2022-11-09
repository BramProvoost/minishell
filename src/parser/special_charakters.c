/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   special_charakters.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 14:38:42 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/09 20:47:51 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	pipe_case(t_line_lst **line_lst)
{
	add_at_end_of_list(line_lst, e_pipe, "|");
	return (1);
}

int	less_than_case(t_line_lst **line_lst, char *line)
{
	if (line[1] == '<')
	{
		add_at_end_of_list(line_lst, e_delimiter, "<<");
		return (2);
	}
	add_at_end_of_list(line_lst, e_redirect_i, "<");
	return (1);
}

int	greater_than_case(t_line_lst **line_lst, char *line)
{
	if (line[1] == '>')
	{
		add_at_end_of_list(line_lst, e_append, ">>");
		return (2);
	}
	add_at_end_of_list(line_lst, e_redirect_o, ">");
	return (1);
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
	return (2);
}

int	dolar_sign_case(t_line_lst **line_lst, char *line, t_quote *qoute)
{
	int		len;
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
	{
		add_at_end_of_list(line_lst, type, "$");
		return (1);
	}
	len = 1;
	while (is_word(line[len], qoute))
		len++;
	add_at_end_of_list(line_lst, e_var, ft_substr(line, 1, len - 1));
	return (len);
}
