/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:55:47 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/16 18:00:51 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(t_pipex *pipex, char **argv, char **env)
{
	is_valid_cmd(pipex, argv[2]);
	init_tab_cmd(pipex, argv[2]);
	close(pipex->tab_fd[0]);
	dup2(pipex->fd_in, 0);
	dup2(pipex->tab_fd[1], 1);
	//open_fd(pipex, argv);
	exec_cmd(pipex, env);
	close(pipex->tab_fd[1]);
}
