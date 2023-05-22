/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:27:20 by neves             #+#    #+#             */
/*   Updated: 2023/05/22 20:16:46 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void first_child(t_pipex pipex, char *argv[], char *envp[])
// {
//     if (dup2(pipex.pipe_fd[1], STDOUT_FILENO) == -1)
//     {
//         perror("dup2");
//         exit(1);
//     }
//     close(pipex.pipe_fd[0]);
//     close(pipex.pipe_fd[1]);
//     if (dup2(pipex.infile, STDIN_FILENO) == -1)
//     {
//         perror("dup2");
//         exit(1);
//     }
//     close(pipex.infile);
//     pipex.cmd_args = ft_split(argv[2], ' ');
//     pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
//     if (!pipex.cmd)
//     {
//         child_free(&pipex);
//         msg("ERROR");
//         exit(1);
//     }
//     execve(pipex.cmd, pipex.cmd_args, envp);
// }

// void second_child(t_pipex pipex, char *argv[], char *envp[])
// {
//     if (dup2(pipex.pipe_fd[0], STDIN_FILENO) == -1)
//     {
//         perror("dup2");
//         exit(1);
//     }
//     close(pipex.pipe_fd[0]);
//     close(pipex.pipe_fd[1]);
//     if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
//     {
//         perror("dup2");
//         exit(1);
//     }
//     close(pipex.outfile);
//     pipex.cmd_args = ft_split(argv[3], ' ');
//     pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
//     if (!pipex.cmd)
//     {
//         child_free(&pipex);
//         msg("ERROR");
//         exit(1);
//     }
//     execve(pipex.cmd, pipex.cmd_args, envp);
// }

void	first_child(t_pipex *pipex, char *argv[], char *envp[])
{
	if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
		msg_error("dup2");
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
		msg_error("dup2");
	close(pipex->infile);
	pipex->cmd_args = ft_split(argv[2], ' ');
	pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
	if (!pipex->cmd)
	{
		child_free(pipex);
		msg("ERROR");
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}

void	second_child(t_pipex *pipex, char *argv[], char *envp[])
{
	if (dup2(pipex->pipe_fd[0], STDIN_FILENO) == -1)
		msg_error("dup2");
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
		msg_error("dup2");
	close(pipex->outfile);
	pipex->cmd_args = ft_split(argv[3], ' ');
	pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
	if (!pipex->cmd)
	{
		child_free(pipex);
		msg("ERROR");
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}
