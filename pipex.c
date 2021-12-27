/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:28:37 by schung            #+#    #+#             */
/*   Updated: 2021/12/26 20:22:51 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//int	open_file()

int	main(int argc, char **argv, char **env)
{
	int		in_fd;
	//int		out_fd;
	//pid_t	pipe;
	char	*t;

	if (argc > 5)
	{
		in_fd = argc;
		t = env[0];
		if (!access(argv[1], F_OK))
			write(1, "xer", 3);
	}
	return (0);
}
