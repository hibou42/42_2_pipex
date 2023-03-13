/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:38:51 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/07 14:50:56 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_cmd(t_pipex *pipex, char **argv, char **env)
{
	char	**tab_cmd;

	(void)argv;
	tab_cmd = ft_calloc(2, sizeof(char *));
	tab_cmd[0] = pipex->cmd_path;
	tab_cmd[1] = NULL;
	execve(pipex->cmd_path, tab_cmd, env);
	free(tab_cmd);
}

/*
execve(char *"PATH", char **"FLAGS", env)
par Flag on entend la commande en flag[0] et les flags en flag[1]
*/