/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:38:51 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/14 14:32:04 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_cmd(t_pipex *pipex, char **env)
{
	execve(pipex->cmd_path, pipex->tab_cmd, env);
}

/*
execve(char *"PATH", char **"FLAGS", env)
par Flag on entend la commande en flag[0] et les flags en flag[1]
*/