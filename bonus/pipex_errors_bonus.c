/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:32:32 by schung            #+#    #+#             */
/*   Updated: 2022/01/19 08:59:04 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../headers/libft.h"

void	pipex_error_message(char *s, int err)
{
	char	*str;

	str = ft_strnjoin(5, "pipex: ", strerror(err), ": ", s, "\n");
	ft_putstr_fd(str, STDERR);
	free(str);
}

void	here_doc(char *argv)
{
	int		file;
	char	*buf;
	int		i;

	i = 1;
	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file < 0)
		ft_putstr_fd(ERR_HEREDOC, STDERR);
	while (i != 0)
	{
		ft_putstr_fd("heredoc> ", STDOUT);
		buf = get_next_line(0);
		if (!buf)
			exit(1);
		i = ft_strncmp(argv, buf, ft_strlen(argv) + 1);
		if (i != 0)
		{
			ft_putstr_fd(buf, file);
			ft_putstr_fd("\n", file);
			free(buf);
		}
	}
	free(buf);
	close(file);
}

void	check_here_doc(int argc, char **argv, t_pipex *pipex)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
	{
		here_doc(argv[2]);
		pipex->in_fd = open_file(TEMP_FILE, FILE_READ);
		pipex->here_doc = 1;
		pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND,
				0777);
	}
	else
	{
		pipex->in_fd = open_file(argv[1], FILE_READ);
		pipex->out_fd = open_file(argv[argc - 1], FILE_WRITE);
	}
}
