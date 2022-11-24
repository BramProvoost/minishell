/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 15:28:56 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/24 18:45:32 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/// @brief Creating words using metacharacters
/// @param line The line read by form the input
/// @param word_desc 
/// @return 
int	get_next_word_form_line(char *line, t_word_desc *word_desc)
{
	int	line_position;

	line_position = 0;
	while (ft_strchr(METACHARACTER, line[line_position]) == NULL)
		line_position++;
	word_desc->word = ft_calloc(line_position + 1, sizeof(char *));
	word_desc->word = ft_substr(line, 0, line_position);
	return (line_position);
}

/// @brief Creating a list of wordt from the input
/// @param line The line read by form the input
/// @return 
t_world_list	*parser(char *line)
{
	int				line_length;
	t_world_list	*word_list;
	t_word_desc		*word_desc;

	line_length = 0;
	word_list = NULL;
	while (line[line_length])
	{
		word_desc = malloc(sizeof(t_word_desc));
		line_length += get_next_word_form_line(&line[line_length], word_desc);
		ft_putendl_fd(word_desc->word, 1);
		free(word_desc);
	}
	return (word_list);
}
