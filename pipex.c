/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:28:37 by schung            #+#    #+#             */
/*   Updated: 2022/01/10 20:35:00 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"
#include "headers/libft.h"

char	*find_path(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

int	open_file(char *s, int rw)
{
	char	*str;

	if (rw == FILE_READ)
	{
		if (access(s, F_OK))
		{
			str = ft_strnjoin(5, "pipex: ", strerror(errno), ": ", s, "\n");
			ft_putstr_fd(str, STDERR);
			free(str);
			exit(1);
		}
		if (access(s, R_OK))
		{
			str = ft_strnjoin(5, "pipex: ", strerror(errno), ": ", s, "\n");
			ft_putstr_fd(str, STDERR);
			free(str);
		}
		return (open(s, O_RDONLY));
	}
	return	(open(s, O_CREAT | O_WRONLY | O_TRUNC, 0777));
}

void	ft_exe_cmd(char **argv, char **env, t_pipex *pipex)
{
	if (pipex->pid)
	{
		pipex->cmd_args = ft_split(argv[3], ' ');
		pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
		execve(pipex->cmd, pipex->cmd_args, env);
	}
	else
	{
		pipex->cmd_args = ft_split(argv[2], ' ');
		pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
		execve(pipex->cmd, pipex->cmd_args, env);	
	}
}

void	tube(t_pipex *pipex)
{
	pipe(pipex->pipe_fd);
	pipex->pid = fork();
	if (pipex->pid)
	{
		close(pipex->pipe_fd[1]);
		dup2(pipex->pipe_fd[0], STDIN);
		waitpid(pipex->pid, NULL, 0);
	}
	else
	{
		close(pipex->pipe_fd[0]);
		dup2(pipex->pipe_fd[1], STDOUT);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		pipex.in_fd = open_file(argv[1], FILE_READ);
		pipex.out_fd = open_file(argv[4], FILE_WRITE);
		dup2(pipex.in_fd, STDIN);
		dup2(pipex.out_fd, STDOUT);
		pipex.paths = find_path(env);
		pipex.cmd_paths = ft_split(pipex.paths, ':');
		tube(&pipex);
		ft_putstr_fd("asdasda", STDERR);
		ft_exe_cmd(argv, env, &pipex);
		ft_putstr_fd("soso", STDERR);
		//pipex_free(&pipex);
	}
	else 
		ft_putstr_fd("pipex: Invalid number of arguments.\n", STDERR);

	while(1)
	{

	}
	return (0);
}