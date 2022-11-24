/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 10:50:17 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/23 13:48:27 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../../libs/libft/libft.h"

# define CCRED "\x1b[0;31m"
# define CCGREEN "\x1b[0;32m"
# define CCYELLOW "\x1b[0;33m"
# define CCBLUE "\x1b[0;34m"
# define CCEND "\x1b[0m"

char	*get_expantion(char * var);

#endif
