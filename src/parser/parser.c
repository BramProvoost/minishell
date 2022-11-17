/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 15:28:56 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/17 19:28:57 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	if (ft_strchr(" |<>&\'\"", line[i]) != NULL)
		 return (0);
	len = i;
	while (ft_strchr(" |<>&\'\"", line[i + len]) == NULL)
		len++;
	if (last == e_start || last == e_pipe)
		add_at_end_of_list(line_lst, e_cmd, ft_substr(line, 0, len));
	if (last == e_cmd || last == e_word || last == e_delimiter || last == e_var)
		add_at_end_of_list(line_lst, e_word, ft_substr(line, 0, len));
	if (last == e_redirect_i || last == e_redirect_o || last == e_append)
		add_at_end_of_list(line_lst, e_file, ft_substr(line, 0, len));
	i += len;
	return (i);
}

// loop until second qoute
int	qoute_case(t_line_lst **line_lst, char *line)
{
	char	qoute;
	int		i;

	qoute = line[0];
	i = 1;
	while (line[i] && line[i] == qoute)
	{
		// if (line[i] == '$' && qoute == '\"')
		// 	; //var
		i++;
	}
	add_at_end_of_list(line_lst, e_word, ft_substr(line, 1, i));
	return (i);
}

t_line_lst	*parser(char *line)
{
	int			i;
	t_line_lst	*line_lst;

	i = 0;
	// line_lst = (t_line_lst *)malloc(sizeof(t_line_lst));
	// line_lst->next = NULL;
	// line_lst->prev = NULL;
	// line_lst->type = e_start;
	// line_lst->value = "";
	line_lst = NULL;
	while (line[i] != '\0')
	{
		if (line[i] == '\'' || line[i] == '\"')
			i += qoute_case(&line_lst, &line[i]);
		// else if (line[i] == '$')
		// 	i += dolar_sign_case(&line_lst, &line[i]);
		else if (ft_strchr("| <>\'\"", line[i]) == NULL)
			i += word_case(&line_lst, &line[i]);
		else if (line[i] == '|')
			i += pipe_case(&line_lst);
		else if (line[i] == '<')
			i += less_than_case(&line_lst, &line[i]);
		else if (line[i] == '>')
			i += greater_than_case(&line_lst, &line[i]);
		else if (line[i] == ' ')
			i++;
	}
	return (line_lst);
}

t_line_lst	*first_expender(t_line_lst *list)
{
	return (list);
}
