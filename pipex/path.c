/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:44:30 by neves             #+#    #+#             */
/*   Updated: 2023/05/25 13:56:46 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(char **paths, char *cmd)
{
	char	*command;
	size_t	path_len;
	size_t	cmd_len;

	command = NULL;
	while (*paths != NULL)
	{
		path_len = ft_strlen(*paths);
		cmd_len = ft_strlen(cmd);
		command = (char *)malloc((path_len + cmd_len + 2) * sizeof(char));
		if (command == NULL)
			return (NULL);
		ft_strcpy(command, *paths);
		command[path_len] = '/';
		ft_strcpy(command + path_len + 1, cmd);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

char	*find_path(char **envp)
{
	char	*path;

	path = NULL;
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path = *envp + 5;
			return (path);
		}
		envp++;
	}
	return (path);
}
