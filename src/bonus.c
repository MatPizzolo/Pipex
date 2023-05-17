/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:21:23 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/04/18 13:26:14 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec(char *cmd, char **envp)
{
	char	**cmdargs;
	char	*path;

	cmdargs = ft_split(cmd, ' ');
	path = get_path(cmdargs[0], envp);
	execve(path, cmdargs, envp);
	perror("pipex: command not found");
	exit(127);
}

void	proces_child(char *cmd, char **envp)
{
	pid_t	child;
	int		pipefds[2];

	pipe(pipefds);
	child = fork();
	if (child)
	{
		close(pipefds[1]);
		dup2(pipefds[0], STDIN_FILENO);
		waitpid(child, NULL, 0);
	}
	else
	{
		close(pipefds[0]);
		dup2(pipefds[1], STDOUT_FILENO);
		exec(cmd, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;
	int	i;

	if (argc == 1)
		printf("pasate unos params pa\n");
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (printf("invalid file/s\n"), -1);
	i = 3;
	dup2(f1, STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	proces_child(argv[2], envp);
	while (i < argc - 2)
		proces_child(argv[i++], envp);
	exec(argv[3], envp);
	printf("\nFinish\n");
	return (0);
}
