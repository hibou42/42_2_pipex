/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:24:47 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/28 14:52:00 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	time_to_fork(t_pipex *pipex, char **argv, char **env)
{
	pipex->pid = fork();
	if (pipex->pid < 0)
		error(pipex, "FORK ERROR\n");
	else if (pipex->pid == 0)
		child_process(pipex, argv, env);
	else
		parent_process(pipex, argv, env);
}
