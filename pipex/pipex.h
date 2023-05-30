/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:00:41 by neves             #+#    #+#             */
/*   Updated: 2023/05/28 08:57:28 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

# define FORK "Unable to fork"
# define MEMORY "Failure allocating memory"
# define DUP2 "dup2 error"
# define INFILE "Failure opening input file"
# define OUTFILE "Failure opening output file"
# define PIPE "Failure creating pipe"

typedef struct s_pipex
{
	char	**cmd_args;
	char	**cmd_paths;
	char	*cmd;
	char	*path;
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

// error

int		msg(char *err);
void	msg_error(char *err);
void	err_handler(t_pipex *pipex, char *err_msg);

// utils

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

// main

void	init_struct(t_pipex **buff);
void	execute_pipeline(t_pipex *pipex, char *argv[], char *envp[]);

// free

void	child_free(t_pipex *pipex);
void	parent_free(t_pipex *pipex);
void	free_all(t_pipex *pipex);

// children

void	first_child(t_pipex *pipex, char *argv[], char *envp[]);
void	second_child(t_pipex *pipex, char *argv[], char *envp[]);

// paths

char	*get_cmd(char **paths, char *cmd);
char	*find_path(char **envp);

#endif
