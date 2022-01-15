/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:39:01 by schung            #+#    #+#             */
/*   Updated: 2022/01/10 20:32:02 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"
#include "headers/libft.h"

void	pipex_errors(char *s, t_pipex *pipex)
{
    ft_putstr_fd("pipex: ", STDERR);
    ft_putstr_fd(s, STDERR);
    ft_putstr_fd(pipex->cmd, STDERR);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

char	*ft_strnjoin(int num, ...)
{
	char			*s1;
	char			*s2;
	char			*sum;
	va_list			list;
	int				i;

	va_start(list, num);
	i = num;
	while (i > 1)
	{
		if (!(num == i))
		{
			s1 = sum;
			free(sum);
		}	
		else
			s1 = va_arg(list, char *);
		s2 = va_arg(list, char *);
		sum = ft_strjoin(s1, s2);
		i--;
	}
	va_end(list);
	return (sum);
}

void	pipex_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->in_fd);
	close(pipex->out_fd);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
    i = 0;
    while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}