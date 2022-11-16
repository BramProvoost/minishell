/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 15:28:56 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/16 10:23:50 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_word(char c)
{
	if (ft_strstr("| <>\'\"$", &c) != NULL)
		return (0);
	// if (c == '\'')
	// 	return (single_qoute_case(qoute));
	// if (c == '\"')
	// 	return (double_qoute_case(qoute));
	// if (qoute->is_single && c != '\0' && c != '$')
	// 	return (1);
	// if (qoute->is_double && c != '\0')
	// 	return (1);
	// if (ft_isalpha(c))
	// 	return (1);
	// if (ft_isdigit(c))
	// 	return (1);
	// if (c == '-')
	// 	return (1);
	// if (ft_strchr("-", c) != NULL)
	// 	return (1);
	// if (c == '$' && qoute->is_single)
	// 	return (1);
	return (1);
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

int	word_case(t_line_lst **line_lst, char *line)
{
	int		i;
	int		len;
	t_note	last;

	i = 0;
	last = get_last_type(*line_lst);
	if (is_word(line[i]))
	{
		len = 0;
		while (is_word(line[i + len]))
			len++;
		if (last == e_start || last == e_pipe)
			add_at_end_of_list(line_lst, e_cmd, ft_substr(line, i, len));
		if (last == e_cmd || last == e_word || last == e_delimiter)
			add_at_end_of_list(line_lst, e_word, ft_substr(line, i, len));
		if (last == e_redirect_i || last == e_redirect_o || last == e_append)
			add_at_end_of_list(line_lst, e_file, ft_substr(line, i, len));
		i += len;
	}
	return (i);
}

int	qoute_case(t_line_lst **line_lst, char c, int *qoutes)
{
	if (c == '\'' && *qoutes != DOUBLE_QOUTE)
	{
		if (*qoutes == SINGLE_QOUTE)
			*qoutes = 0;
		else
		{
			*qoutes = SINGLE_QOUTE;
			add_at_end_of_list(line_lst, e_qoute, "\'");
		}
		return (1);
	}
	if (c == '\"' && *qoutes != SINGLE_QOUTE)
	{
		if (*qoutes == DOUBLE_QOUTE)
			*qoutes = 0;
		else
		{
			*qoutes = DOUBLE_QOUTE;
			add_at_end_of_list(line_lst, e_dqoute, "\"");
		}
		return (1);
	}
	return (0);
}

t_line_lst	*parser(char *line)
{
	int			i;
	int			qoutes;
	t_line_lst	*line_lst;

	i = 0;
	qoutes = 0;
	line_lst = NULL;
	while (line[i] != '\0')
	{
		// if (line[i] == '\'' || line[i] == '\"')
		// 	i += qoute_case(&line_lst, line[i], &qoutes);
		if (line[i] == '$')
			i += dolar_sign_case(&line_lst, &line[i]);
		if (is_word(line[i]))
			i += word_case(&line_lst, &line[i]);
		if (line[i] == '|')
			i += pipe_case(&line_lst);
		if (line[i] == '<')
			i += less_than_case(&line_lst, &line[i]);
		if (line[i] == '>')
			i += greater_than_case(&line_lst, &line[i]);
		if (line[i] == ' ')
			i++;
	}
	return (line_lst);
}
