/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:47:02 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/31 16:16:30 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	pipex = (t_pipex){};
	init_path(env, &pipex);
	check_arg(argc, argv, &pipex);
	init_pipe(&pipex);
	time_to_fork(&pipex, argv, env);
	fd_close(&pipex);
	waitpid(pipex.pid[0], NULL, 0);
	waitpid(pipex.pid[1], NULL, 0);
	free_and_exit(&pipex, 0);
	return (0);
}
