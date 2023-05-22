/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:00:41 by neves             #+#    #+#             */
/*   Updated: 2023/05/22 20:07:30 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

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

int		msg(char *err);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*find_path(char **envp);
void	execute_pipeline(t_pipex *pipex, char *argv[], char *envp[]);
void	child_free(t_pipex *pipex);
void	parent_free(t_pipex *pipex);
void	msg_error(char *err);
void	first_child(t_pipex *pipex, char *argv[], char *envp[]);
void	second_child(t_pipex *pipex, char *argv[], char *envp[]);
char	*get_cmd(char **paths, char *cmd);

#endif

// View list of process in system 
// top or ps