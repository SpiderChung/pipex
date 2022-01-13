/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:56:45 by schung            #+#    #+#             */
/*   Updated: 2022/01/10 20:31:51 by schung           ###   ########.fr       */
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


typedef struct s_pipex
{
	int	    in_fd;
	int 	out_fd;
    int     pipe_fd[2];
    pid_t   pid;
    char    *paths;
    char    **cmd_paths;
    char    **cmd_args;
    char    *cmd;
}	t_pipex;


/*________pipex.c__________*/

/*________pipex_utils.c__________*/
void	pipex_errors();
char	*ft_strnjoin(int num, ...);
void	pipex_free(t_pipex *pipex);
char	*get_cmd(char **paths, char *cmd);

#endif