/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 10:50:05 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/23 11:41:20 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*get_expantion(char * str)
{
	char 	*var;

	var = ft_strjoin(CCYELLOW, str);	// temp for testing
	var = ft_strjoin(var, CCEND);		// temp for testing
	return (var);
}
