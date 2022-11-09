/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 15:28:56 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/09 21:12:39 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_word(char c, t_quote *qoute)
{
	if (ft_isalpha(c))
		return (1);
	if (ft_isdigit(c))
		return (1);
	if (c == '-')
		return (1);
	if (c == '$' && qoute->is_single)
		return (1);
	return (0);
}

t_note	get_last_type(t_line_lst *node)
{
	t_note	type;

	type = e_start;
	while (node != NULL)
	{
		type = node->type;
		node = node->next;
	}
	return (type);
}

int	word_case(t_line_lst **line_lst, char *line, t_quote *qoute)
{
	int		i;
	int		len;
	t_note	last;

	i = 0;
	last = get_last_type(*line_lst);
	if (is_word(line[i], qoute))
	{
		len = 0;
		while (is_word(line[i + len], qoute))
			len++;
		if (last == e_start || last == e_pipe)
			add_at_end_of_list(line_lst, e_cmd, ft_substr(line, i, len));
		if (last == e_cmd || last == e_word || last == e_delimiter)
			add_at_end_of_list(line_lst, e_word, ft_substr(line, i, len));
		if (last == e_redirect_i || last == e_redirect_o || last == e_append)
			add_at_end_of_list(line_lst, e_file, ft_substr(line, i, len));
		i += len;
	}
	return (i + 1);
}

t_line_lst	*parser(char *line)
{
	int			i;
	t_line_lst	*line_lst;
	t_quote		*quote;

	i = 0;
	line_lst = NULL;
	quote = init_qoutes();
	while (line[i] != '\0')
	{
		if (is_word(line[i], quote))
			i += word_case(&line_lst, &line[i], quote);
		if (line[i] == '|')
			i += pipe_case(&line_lst);
		if (line[i] == '<')
			i += less_than_case(&line_lst, &line[i]);
		if (line[i] == '>')
			i += greater_than_case(&line_lst, &line[i]);
		if (line[i] == '$')
			i += dolar_sign_case(&line_lst, &line[i], quote);
		if (line[i] == '\'')
			i += single_qoute_case(quote);
		if (line[i] == '"')
			i += double_qoute_case(quote);
	}
	return (line_lst);
}
