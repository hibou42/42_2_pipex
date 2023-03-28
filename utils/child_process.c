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
	pipex->tab_cmd = ft_split(argv[2], ' ');
	if(is_valid_cmd(pipex) != 0)
		error(pipex, "command not found");
	close(pipex->tab_fd[0]);
	dup2(pipex->fd_in, 0);
	dup2(pipex->tab_fd[1], 1);
	execve(pipex->cmd_path, pipex->tab_cmd, env);
	close(pipex->tab_fd[1]);
}
