/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:06:41 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/31 16:14:33 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child2_process(t_pipex *pipex, char **argv, char **env)
{
	pipex->fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (pipex->fd_out < 0)
		error(pipex, "error open", NULL);
	pipex->tab_cmd = ft_split(argv[3], ' ');
	if (is_valid_cmd(pipex) != 0)
		error(pipex, "command not found", argv[3]);
	if (dup2(pipex->tab_fd[0], 0) < 0)
		error(pipex, "error dup2", NULL);
	if (dup2(pipex->fd_out, 1) < 0)
		error(pipex, "error dup2", NULL);
	fd_close(pipex);
	if (execve(pipex->cmd_path, pipex->tab_cmd, env) < 0)
		error(pipex, "error execve", NULL);
}
