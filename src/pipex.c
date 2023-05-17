#include "../pipex.h"

void	exec(char *cmd, char **envp)
{
	char	**cmdargs;
	char	*path;

	cmdargs = ft_split(cmd, ' ');
	path = get_path(cmdargs[0], envp);
	if (!path)
	{
		perror("Command not found");
		exit(127);
	}
	if (execve(path, cmdargs, envp) == -1)
	{	
		perror("pipex");
		exit(127);
	}
}

void	run_child1(int f1, char **argv, char **envp, int pipefds[2])
{
	close(pipefds[0]);
	dup2(f1, STDIN_FILENO);
	dup2(pipefds[1], STDOUT_FILENO);
	close(pipefds[1]);
	exec(argv[2], envp);
}

void	run_child2(int f2, char **argv, char **envp, int pipefds[2])
{
	close(pipefds[1]);
	dup2(pipefds[0], STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	close(pipefds[0]);
	exec(argv[3], envp);
}

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int		pipefds[2];
	pid_t	child1_pid;
	pid_t	child2_pid;

	if (pipe(pipefds) == -1)
		error();
	child1_pid = fork();
	if (child1_pid == -1)
		error();
	else if (child1_pid == 0)
		run_child1(f1, argv, envp, pipefds);
	else
	{
		child2_pid = fork();
		if (child2_pid == -1)
			error();
		else if (child2_pid == 0)
			run_child2(f2, argv, envp, pipefds);
		else
		{
			close_fds(pipefds);
			waitpid(child1_pid, NULL, 0);
			waitpid(child2_pid, NULL, 0);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	if (argc != 5)
		return (printf("Usage: %s infile cmd1 cmd2 outfile\n", argv[0]), 1);
	f1 = open(argv[1], O_RDONLY);
	if (f1 < 0)
	{
		perror(argv[1]);
		return (1);
	}
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f2 < 0)
	{	
		close(f1);
		perror(argv[4]);
		exit(127);
	}
	pipex(f1, f2, argv, envp);
	close(f1);
	close(f2);
	return (0);
}
