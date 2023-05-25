/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:27:20 by neves             #+#    #+#             */
/*   Updated: 2023/05/25 13:48:39 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex *pipex, char *argv[], char *envp[])
{
	if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
		err_handler(pipex, DUP2); // TODO: Error handling
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
		err_handler(pipex, DUP2); // TODO: Error handling
	close(pipex->infile);
	pipex->cmd_args = ft_split(argv[2], ' ');
	// TODO: Error handling
	if (!pipex->cmd_args)
		err_handler(pipex, MEMORY);
	pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
	if (!pipex->cmd)
	{
		// TODO: Error handling
		err_handler(pipex, MEMORY);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}

void	second_child(t_pipex *pipex, char *argv[], char *envp[])
{
	if (dup2(pipex->pipe_fd[0], STDIN_FILENO) == -1)
		err_handler(pipex, DUP2);;
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
		err_handler(pipex, DUP2);;
	close(pipex->outfile);
	pipex->cmd_args = ft_split(argv[3], ' ');
	if (!pipex->cmd_args)
		err_handler(pipex, MEMORY);
	// TODO: Error handling
	pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
	if (!pipex->cmd) 
	{// TODO: Error handling
		err_handler(pipex, MEMORY);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}
