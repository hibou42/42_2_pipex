/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:55:47 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/31 16:15:08 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(t_pipex *pipex, char **argv, char **env)
{
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in < 0)
		error(pipex, "error open", NULL);
	pipex->tab_cmd = ft_split(argv[2], ' ');
	if (is_valid_cmd(pipex) != 0)
		error(pipex, "command not found", argv[2]);
	if (dup2(pipex->fd_in, 0) < 0)
		error(pipex, "error dup2", NULL);
	if (dup2(pipex->tab_fd[1], 1) < 0)
		error(pipex, "error dup2", NULL);
	fd_close(pipex);
	if (execve(pipex->cmd_path, pipex->tab_cmd, env) < 0)
		error(pipex, "error execve", NULL);
}
