/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:56:45 by schung            #+#    #+#             */
/*   Updated: 2022/01/15 18:45:56 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdarg.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define FILE_READ 0
# define FILE_WRITE 1
# define ERR_CMD "Command not found"

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		pipe_fd[2];
	pid_t	pid;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

/*_____________pipex.c_____________*/
char	*find_path(char **env);
int		open_file(char *s, int rw);
void	ft_exe_cmd(char **argv, char **env, t_pipex *pipex);
void	tube(t_pipex *pipex);

/*_____________pipex_utils.c_____________*/
void	pipex_errors(char *s, t_pipex *pipex);
char	*ft_strnjoin(int num, ...);
void	pipex_free(t_pipex *pipex);
char	*get_cmd(char **paths, char *cmd);
void	pipex_error_message(char *s, int err);

#endif
