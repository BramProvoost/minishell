/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 20:08:09 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/11/21 01:03:18 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../main/main.h"

char	**append_env(char **envp, char *variable)
{
	int		i;
	int		j;
	char	**new_envp;

	i = 0;
	
	if (!envp)
		return(NULL);
	while(envp[i])
		i++;
	new_envp = malloc(sizeof(char *) * i + 2);
	if (!new_envp)
		return (NULL);
	j = 0;
	while(j < i)
	{
		new_envp[j] = ft_strdup(envp[j]);
		j++;
	}
	new_envp[j] = ft_strdup(variable);
	return (new_envp);
}

char	**change_env(char **envp, char *variable, char *change)
{
	int		i;
	int		j;
	char	**new_envp;

	i = 0;
	
	if (!envp)
		return(NULL);
	while(envp[i])
		i++;
	new_envp = malloc(sizeof(char *) * i + 1);
	if (!new_envp)
		return (NULL);
	j = 0;
	while(j < i)
	{
		if (ft_strncmp(new_envp[j], variable, ft_strlen(variable) - 1 ) == 0)
			new_envp[j] = ft_strdup(change);
		else
			new_envp[j] = ft_strdup(envp[j]);
		j++;
	}
	return (new_envp);
}

char	**remove_env(char **envp, char *variable)
{
	int		i;
	int		j;
	int		k;
	char	**new_envp;

	i = 0;
	
	if (!envp)
		return(NULL);
	while(envp[i])
		i++;
	new_envp = malloc(sizeof(char *) * i);
	if (!new_envp)
		return (NULL);
	j = 0;
	k = 0;
	while(j < i)
	{
		if (ft_strncmp(new_envp[k], variable, ft_strlen(variable) - 1) == 0)
		{
			new_envp[j] = ft_strdup(variable);
			k++;
		}
		else
			new_envp[j] = ft_strdup(envp[k]);
		k++;
	}
	while(*new_envp++)
		message(*new_envp);
	return (new_envp);
}

// export in env, zonder =, zet = erachter.
// anders de rest van de string
int	check_env_exist(char **cmd, t_data *data)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	
	while((cmd[1][i] && cmd[1][i] != '=') && j == 0)
		i++;
	str = malloc(i + 1 * (sizeof(char)));
	ft_strlcpy(str, cmd[1], i + 1);
	message_nl("cmd1 = ");
	message(str);
	while(data->envp[j])
	{
		if(!ft_strncmp(data->envp[j], str, i))
			break;
		j++;
	}
	if (data->envp[j])
	{
		message_nl("exists ");
		message(data->envp[j]);
		return(1);
	}
	else
	{
		message("doesnt exists ");
		message(cmd[1]);
		return(0);
	}
}

void	export_(char **cmd, t_data *data)
{
	char *str;
	int exists;
	int varlen;
	int flag;

	flag = 0;
	varlen = ft_strlen(cmd[1]);
	exists = check_env_exist(cmd, data);
	if (varlen == 0)
		while(data->envp++)
			printf("%s\n", *data->envp);
	else if (exists == 1)
	{
		// geen = met tekst betekent niets doen.
		if(ft_strncmp(cmd[1], "=", 1))
		{
			flag = 1;
			str = ft_strjoin(cmd[1], "=");
			message("doe niets");
		}
		else
			change_env(data->envp, cmd[1], "test");
	}
	else
		message("verander niet bestaande env");
}

void	execute_export(char **cmd, t_data *data)
{
	int i;

	i = 0;
	if (cmd[1])
		export_(cmd, data);
	else
		while(data->envp[i++] && data->envp[i+1])
		{
			message(data->envp[i]);
		}
		if (data->envp[i])
			message_nl(data->envp[i]);
}