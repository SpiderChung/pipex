/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:28:37 by schung            #+#    #+#             */
/*   Updated: 2022/01/15 18:40:50 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../headers/libft.h"

char	*find_path(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

int	open_file(char *s, int rw)
{
	if (rw == FILE_READ)
	{
		if (access(s, F_OK | R_OK))
		{
			pipex_error_message(s, errno);
			exit(1);
		}
		return (open(s, O_RDONLY));
	}
	else
	{
		if (!(access(s, F_OK)))
		{
			if (access(s, W_OK))
			{
				pipex_error_message(s, errno);
				exit(1);
			}
		}
		return (open(s, O_CREAT | O_WRONLY | O_TRUNC, 0777));
	}
}

void	ft_exe_cmd(char *argv, char **env, t_pipex *pipex)
{
	pipex->cmd_args = ft_split(argv, ' ');
	pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
	if (!pipex->cmd)
	{
		pipex_errors(ERR_CMD, pipex);
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, env);
}

void	tube(char *argv, char **env, t_pipex *pipex)
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
		ft_exe_cmd(argv, env, pipex);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	pipex.here_doc = 0;
	pipex.quantity = pipex.here_doc + 3;
	if (argc >= 5)
	{
		check_here_doc(argc, argv, &pipex);
		dup2(pipex.in_fd, STDIN);
		dup2(pipex.out_fd, STDOUT);
		pipex.paths = find_path(env);
		pipex.cmd_paths = ft_split(pipex.paths, ':');
		tube(argv[2 + pipex.here_doc], env, &pipex);
		while (pipex.quantity < argc - 2)
		{
			tube(argv[pipex.quantity++], env, &pipex);
		}
		ft_exe_cmd(argv[pipex.quantity], env, &pipex);
		pipex_free(&pipex);
	}
	else
		ft_putstr_fd("pipex: Invalid number of arguments.\n", STDERR);
	return (0);
}
