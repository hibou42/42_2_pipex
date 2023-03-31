/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:24:47 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/31 15:51:24 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	time_to_fork(t_pipex *pipex, char **argv, char **env)
{
	pipex->pid[0] = fork();
	if (pipex->pid[0] < 0)
		error(pipex, "FORK ERROR\n", NULL);
	else if (pipex->pid[0] == 0)
		child_process(pipex, argv, env);
	pipex->pid[1] = fork();
	if (pipex->pid[1] < 0)
		error(pipex, "FORK ERROR\n", NULL);
	else if (pipex->pid[1] == 0)
		child2_process(pipex, argv, env);
}
