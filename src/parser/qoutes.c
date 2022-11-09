/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   qoutes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 17:57:00 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/09 20:14:52 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>	// temp printf

t_quote	*init_qoutes(void)
{
	t_quote	*qoute;

	qoute = (t_quote *)malloc(sizeof(t_quote));
	qoute->is_single = 0;
	qoute->is_double = 0;
	return (qoute);
}

int		single_qoute_case(t_quote *qoute)
{
	qoute->is_single = ~qoute->is_single;
	return (1);
}

int		double_qoute_case(t_quote *qoute)
{
	qoute->is_double = ~qoute->is_double;
	return (1);
}
