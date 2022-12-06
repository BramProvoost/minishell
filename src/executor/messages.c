/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:37:15 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/11/25 16:26:25 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../executor/executor.h"

void	message_exit(char *message, int errornumber)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(errornumber);
}

void	message_nl(char *msg)
{
	ft_putstr_fd(msg, 2);
}

void	message(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}