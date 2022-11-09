/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:46:28 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/09 20:11:44 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../libs/libft/libft.h"
# include <stdlib.h>

/*
	+------+-------+------+     +------+-------+------+     +------+-------+------+
	| prev | type  | next | <-> | prev | type  | next | <-> | prev | type  | next |
	+------+       +------+     +------+       +------+     +------+       +------+
	       | value |                   | value |                   | value |       
	       +-------+                   +-------+                   +-------+       
*/
typedef struct s_line_lst
{
	int					type;
	char				*value;
	struct s_line_lst	*next;
	struct s_line_lst	*prev;
}	t_line_lst;

typedef struct s_quote
{
	int is_single;
	int	is_double;
}	t_quote;

typedef enum e_note{
	e_start = -2,
	e_stop = -1,
	e_cmd,
	e_file,
	e_pipe,
	e_word,
	e_var,
	e_redirect_i,
	e_redirect_o,
	e_delimiter,
	e_append
}	t_note;

/* The parser processes the input line and build the list with tokens */
t_line_lst	*parser(char *line);
int			word_case(t_line_lst **line_lst, char *line, t_quote *qoute);
int			is_word(char c, t_quote *qoute);
t_note		get_last_type(t_line_lst *node);
int			pipe_case(t_line_lst **line_lst);
int			less_than_case(t_line_lst **line_lst, char *line);
int			greater_than_case(t_line_lst **line_lst, char *line);
int			dolar_sign_case(t_line_lst **line_lst, char *line, t_quote *qoute);
char		*type_to_string(t_note type);
void		show_t_list(t_line_lst *node, char *input_line);
void		delete_t_list(t_line_lst **head);
void		add_at_end_of_list(t_line_lst **head, int type, char *value);
int			length_of_list(t_line_lst *node);

t_quote		*init_qoutes(void);
int			single_qoute_case(t_quote *qoute);
int			double_qoute_case(t_quote *qoute);

#endif
