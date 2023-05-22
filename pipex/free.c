/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:17:15 by neves             #+#    #+#             */
/*   Updated: 2023/05/22 19:26:23 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_free(t_pipex *pipex)
{
	char	**paths;

	close(pipex->infile);
	close(pipex->outfile);
	paths = pipex->cmd_paths;
	while (*paths)
	{
		free(*paths);
		paths++;
	}
	free(pipex->cmd_paths);
}

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
