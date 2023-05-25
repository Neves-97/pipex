/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:44:30 by neves             #+#    #+#             */
/*   Updated: 2023/05/25 13:47:12 by roda-min         ###   ########.fr       */
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
			return (NULL); //DONE
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

// The function takes two parameters: char **paths and char *cmd. Let's go through the function step by step:

//     char *command;: This declares a pointer command of type char which will be used to store the final command.

//     size_t path_len;: This variable will hold the length of the current path.

//     size_t cmd_len;: This variable will hold the length of the command.

//     command = NULL;: Initially, the command variable is set to NULL.

//     while (*paths != NULL): This is a loop that iterates over the paths array until it encounters a NULL value, indicating the end of the array.

//     Inside the loop:
//         path_len = ft_strlen(*paths);: The length of the current path (*paths) is calculated using the ft_strlen function (which is not shown in the provided code).
//         cmd_len = ft_strlen(cmd);: The length of the command (cmd) is calculated using the ft_strlen function (which is not shown in the provided code).
//         command = (char *)malloc((path_len + cmd_len + 2) * sizeof(char));: Memory is dynamically allocated for the command string. The total size needed is (path_len + cmd_len + 2) because 
// 		it includes the lengths of the path, command, and an extra character for the slash ('/') and a null terminator.
//         if (command == NULL) return (NULL);: If the memory allocation fails, NULL is returned to indicate an error.
//         ft_strcpy(command, *paths);: The current path (*paths) is copied into the command string.
//         command[path_len] = '/';: A slash character ('/') is added at the end of the path.
//         ft_strcpy(command + path_len + 1, cmd);: The command (cmd) is appended to the command string after the slash character.

//     After constructing the command string, the function checks if the command is accessible using the access function. If the command is accessible (i.e., it exists and can be executed), the command string is returned.
//         if (access(command, 0) == 0) return (command);: The access function checks the accessibility of the specified file or directory. It returns 0 if the file exists and has the required permissions, otherwise it returns -1.

//     If the command is not accessible, the dynamically allocated memory for command is freed using free(command) and the loop moves to the next path by incrementing the paths pointer.

//     If none of the paths yield an accessible command, the function returns NULL to indicate that the command could not be found.

// That's the complete explanation of the get_cmd function. It takes an array of paths and a command, tries to find the command by concatenating each path with the command, and returns the first accessible command it finds.

// 	free(command);
// 	paths++;
// }
// return (NULL);

//     After the loop, the function frees the dynamically allocated memory for the command string using free(command) to prevent memory leaks.

//     paths++;: The paths pointer is incremented to move to the next path in the paths array.

//     If none of the paths yield an accessible command, the function reaches this point and returns NULL to indicate that the command could not be found.

// To summarize, the get_cmd function takes an array of paths and a command. It iterates over each path, constructs a command string by concatenating the path and command with a slash character in between, and checks if the command 
// is accessible using the access function. If an accessible command is found, it is returned. If no accessible command is found, it returns NULL

// The function find_path takes one parameter: char **envp, which represents the environment variables.

//     char *path;: This declares a pointer path of type char that will store the value of the PATH environment variable.

//     path = NULL;: Initially, the path variable is set to NULL.

//     while (*envp != NULL): This is a loop that iterates over the envp array, which contains the environment variables, until it encounters a NULL value, indicating the end of the array.

//     Inside the loop:

//         if (ft_strncmp(*envp, "PATH=", 5) == 0): This condition checks if the current environment variable (*envp) starts with the string "PATH=". ft_strncmp is used to compare the first 5 characters of the 
// 		environment variable with "PATH=".

//         If the condition is true, it means the current environment variable is the PATH variable.
//             path = *envp + 5;: The path variable is assigned the address of the character right after "PATH=", effectively pointing to the value of the PATH variable.
//             return (path);: The function returns the path variable, which contains the value of the PATH variable.

//         If the condition is false, it means the current environment variable is not the PATH variable.
//             envp++;: The envp pointer is incremented to move to the next environment variable.

//     If the loop completes without finding the PATH variable, i.e., if none of the environment variables start with "PATH=", the function reaches this point.
//         return (path);: The function returns the path variable, which is still NULL at this point, indicating that the PATH variable was not found.

// In summary, the find_path function searches through the environment variables for the PATH variable. It iterates over each environment variable and 
// checks if it starts with "PATH=". If it finds the PATH variable, it returns its corresponding value. If it doesn't find the PATH variable, it returns NULL.