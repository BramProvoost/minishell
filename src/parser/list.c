/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 13:50:10 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/17 15:24:16 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>	// temp for show_t_list function 

char	*type_to_string(t_note type)
{
	if (type == e_start)
		return ("start\t");
	if (type == e_cmd)
		return ("cmd\t");
	if (type == e_file)
		return ("file\t");
	if (type == e_pipe)
		return ("pipe\t");
	if (type == e_word)
		return ("word\t");
	if (type == e_var)
		return ("var\t");
	if (type == e_redirect_i)
		return ("redirect_i");
	if (type == e_redirect_o)
		return ("redirect_o");
	if (type == e_delimiter)
		return ("delimiter");
	if (type == e_append)
		return ("append\t");
	if (type == e_qoute)
		return ("single qoute");
	if (type == e_dqoute)
		return ("double qoute");
	return ("no type");
}

void	show_t_list(t_line_lst *node, char *input_line)
{
	int	i;

	i = 1;
	printf("\ninput_line = \"%s\"", input_line);
	printf("\n---------- line list table -----------\n");
	printf("index\ttype\ttype_name\tvalue\n");
	while (node != NULL)
	{
		printf("%d\t%d\t%s\t\"%s\"\n", i, node->type, \
				type_to_string(node->type), node->value);
		node = node->next;
		i++;
	}
	printf("-------- end line list table ---------\n\n");
}

void	delete_t_list(t_line_lst *head)
{
	t_line_lst	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->value);
		free(temp);
	}
}

void	add_at_end_of_list(t_line_lst **head, int type, char *value)
{
	t_line_lst	*new_node;
	t_line_lst	*temp;

	new_node = (t_line_lst *)malloc(sizeof(t_line_lst));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->type = type;
	new_node->value = value;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

int	length_of_list(t_line_lst *node)
{
	int	lenght;

	lenght = 0;
	while (node != NULL)
	{
		node = node->next;
		lenght++;
	}
	return (lenght);
}
