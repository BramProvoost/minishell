/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 11:51:52 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/11/09 17:01:01 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../main/main.h"

/*
int chdir(const char *path); 	
Used to change the current working directory.
On some systems, this command is used as an alias for the shell command cd. 
chdir changes the current working directory of the calling process to the directory
specified in path.
*/

/* char *getcwd(char *buf, size_t size); 	
Gets the path name of the current working directory. 
If a buffer is specified, the path name is placed in that buffer,
and the address of the buffer is returned. 
Otherwise, 
getcwd() allocates space for the path name and returns a pointer to that buffer. 
In that instance, the user is responsible for deleting the storage when it is 
no longer needed by calling free() with the pointer returned by getcwd(). 
Copies an absolute pathname of the current working directory to the array 
pointed to by buf, which is of length size.
*/

void	update_old_pwd(char *oldpath, t_data *data)
{
	int i;
	char *updated_pwd;

	updated_pwd = ft_strjoin("OLDPWD=", oldpath);
	i = 0;
	while(*data->envp != NULL)
	{
		if (!strncmp(*data->envp, "OLDPWD=", 7))
			ft_strlcpy(*data->envp, updated_pwd, ft_strlen(updated_pwd));
		data->envp++;
	}
	free(updated_pwd);
}

void	cd_home(char **envp)
{
	int i;

	i = 0;
	while(*envp != NULL)
	{
		if (!strncmp(*envp, "HOME=", 5))
			change_dir(*envp+5, "");
		envp++;
	}
}

int		change_dir(char *oldpath, char *path)
{
	char *new_dir_slash;
	char *new_dir;

	new_dir_slash = ft_strjoin(oldpath, "/");
	new_dir = ft_strjoin(new_dir_slash, path);
	if (chdir(new_dir) != 0)
	{
		//write(1, "chdir\n", 7);
		return(1);
	}
	free(new_dir_slash);
	free(new_dir);
	return(0);
}

void	execute_cd(char **cmd, t_data *data)
{
	char 	*oldpath;
	int		status;
    char    cwd[4096 + 1];
	
	status = 0;
	oldpath = getcwd(cwd, 4097);
	
	if (cmd[1] == NULL || (cmd[1][0] == '~' && cmd[1][1] == '\0'))
		cd_home(data->envp);
	else if (cmd[1][0] == '.' && cmd[1][1] == '\0')
		;//update old pwd
	else if (cmd[1][0] == '.' && cmd[1][1] == '.')
	{
		//werkt niet, laatste woord moet eraf.
		change_dir(oldpath, cmd[1]);
	}
	else
		status = change_dir(oldpath, cmd[1]);
	// if (status == 0)
	// 	update_old_pwd( oldpath, data);
	free(oldpath);
}
