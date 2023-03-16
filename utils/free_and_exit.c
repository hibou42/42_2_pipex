/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:38:51 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/16 17:39:12 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_and_exit(t_pipex *pipex, int force_exit)
{
	(void)pipex;
	if (force_exit == 1)
		exit(1);
	exit(0);
}

/*
void	free1(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->path)
	{
		while (pipex->path[i])
		{
			free(pipex->path[i]);
			i++;
		}
		free(pipex->path);
	}
	i = 0;
	if (pipex->tab_cmd)
	{
		while (pipex->tab_cmd[i])
		{
			free(pipex->tab_cmd[i]);
			i++;
		}
		free(pipex->tab_cmd);
	}
}

void	free2(t_pipex *pipex)
{
	if (pipex->cmd_path)
		free(pipex->cmd_path);
}
*/