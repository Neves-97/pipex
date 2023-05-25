/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:42:51 by neves             #+#    #+#             */
/*   Updated: 2023/05/25 13:37:17 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Function to handle the setup and execution of the pipeline
// void execute_pipeline(t_pipex *pipex, char *argv[], char *envp[]) {
//     if (pipe(pipex->pipe_fd) < 0)
//         msg_error("Error: Failed to create pipe.");
//
//     pipex->path = find_path(envp);
//     pipex->cmd_paths = ft_split(pipex->path, ':');
//
//     pipex->pid1 = fork();
//     if (pipex->pid1 == 0)
//         first_child(pipex, argv, envp);
//
//     pipex->pid2 = fork();
//     if (pipex->pid2 == 0)
//         second_child(pipex, argv, envp);
//
//     close_pipes(pipex);
//     waitpid(pipex->pid1, NULL, 0);
//     waitpid(pipex->pid2, NULL, 0);
// }
//
// int main(int argc, char *argv[], char *envp[]) {
//     t_pipex pipex;
//
//     if (argc != 5)
//         return msg("Error: Use ./prog infile cmd1 cmd2 outfile\n");
//    
//     pipex.infile = open(argv[1], O_RDONLY);
//     if (pipex.infile < 0)
//         msg_error("Error: Failed to open input file.");
//   
//     pipex.outfile = open(argv[argc - 1], 
//O_TRUNC | O_CREAT | O_RDWR, 0000644);
//     if (pipex.outfile < 0)
//         msg_error("Error: Failed to open output file.");
//
//     execute_pipeline(&pipex, argv, envp);
//    
//     parent_free(&pipex);
//     return 0;
// }

// Function to handle the setup and execution of the pipeline

void init_struct(t_pipex **buff)
{
	t_pipex *pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(EXIT_FAILURE);
	pipex->cmd = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_paths = NULL;
	pipex->path = NULL;
	pipex->infile = -1;
	pipex->outfile = -1;
	*buff = pipex;
}

void	execute_pipeline(t_pipex *pipex, char *argv[], char *envp[])
{
	if (pipe(pipex->pipe_fd) < 0)
		msg_error("Error: Failed to create pipe.");
	pipex->path = find_path(envp);
	pipex->cmd_paths = ft_split(pipex->path, ':');
	if (!pipex->cmd_paths)
		err_handler(pipex, MEMORY);
	//TODO: Error handling
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		// TODO: Error handling
		err_handler(pipex, FORK);
	if (pipex->pid1 == 0)
		first_child(pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		// TODO: Error handling
		err_handler(pipex, FORK);
	if (pipex->pid2 == 0)
		second_child(pipex, argv, envp);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	if (argc != 5)
		return (msg("Error: Use ./prog infile cmd1 cmd2 outfile\n"));
	init_struct(&pipex); // Init everything to Null
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		err_handler(pipex, INFILE);
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->outfile < 0)
		err_handler(pipex, OUTFILE);
	execute_pipeline(pipex, argv, envp);
	free_all(pipex);
	return (0);
}
