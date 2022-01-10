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

int	open_file(char *s)
{
	char	*str;

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
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	//int		in_fd;
	//int		out_fd;
	//pid_t	pipe;
	int		rd;
	//char	*err;
	//int		i;

	if (argc == 5)
	{
		open_file(argv[1]);
		rd = open(argv[1], O_RDONLY);
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