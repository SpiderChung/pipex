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

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
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
	return	(open(s, O_CREAT | O_WRONLY | O_TRUNC, 0777))
}

void	exe_cmd(char **argv, char **env, pid_t	pid)
{

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
		close(pipex->pipe_fd[1]);
		dup2(pipex->pipe_fd[0], STDIN);
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
		tube(&pipex);
		exe_cmd(argv, env, pipex.pid);
		
		//perror("file");
		printf("wqeqwe %s\n", env[5]);
		/*if (rd < 0)
		{
			err = ft_strjoin("pipex: ", argv[1]);
			errno = 13;
			perror(err);
			free(err);
			i = 0;
			while (env[i])
			{
				printf("wqeqwe %s\n", env[i]);
				i++;
			}
		}
		*/
	}
	else 
		ft_putstr_fd("pipex: Invalid number of arguments.\n", STDERR);
	return (0);
}