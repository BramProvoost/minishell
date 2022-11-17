/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   argv_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 21:10:54 by bprovoos      #+#    #+#                 */
/*   Updated: 2022/11/16 19:49:13 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_argv_in_line(int argc, char *argv[], char **line)
{
	int	index;

	index = 2;
	*line = &argv[1][index];
	while (index < argc)
	{
		*line = ft_strjoin(*line, argv[index]);
		index++;
		if (index < argc)
			*line = ft_strjoin(*line, " ");
	}
}

int	argv_has_flag(int argc, char *argv[])
{
	if (argc < 2)
		return (0);
	if (ft_strlen(argv[1]) < 2)
		return (0);
	if (ft_strncmp(argv[1], "-c", ft_strlen(argv[1])) != 0)
		return (0);
	return (1);
}

int	input_is_argv(int argc, char *argv[], char **line)
{
	if (!argv_has_flag(argc, argv))
		return (0);
	put_argv_in_line(argc, argv, line);
	return (1);
}
