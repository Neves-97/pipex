/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:17:15 by neves             #+#    #+#             */
/*   Updated: 2023/05/25 13:46:51 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// void	parent_free(t_pipex *pipex)
// {
// 	char	**paths;

// 	close(pipex->infile);
// 	close(pipex->outfile);
// 	paths = pipex->cmd_paths;
	
// 	free(pipex->cmd_paths);
// }

void	child_free(t_pipex *pipex)
{
	char	**args;

	args = pipex->cmd_args;
	while (*args)
	{
		free(*args);
		args++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	err_handler(t_pipex *pipex, char *err_msg)
{
	printf("Error: %s\n", err_msg);
	free_all(pipex);
	exit(EXIT_FAILURE);
}

void	free_all(t_pipex *pipex)
{
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	if (pipex->cmd_args)
		free_split(pipex->cmd_args);
	if (pipex->cmd)
		free(pipex->cmd);
	if (pipex->cmd_paths)
		free_split(pipex->cmd_paths);
	if (pipex)
		free(pipex);
}
