/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:38:51 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/07 14:50:56 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_and_exit(t_pipex *pipex, int force_exit)
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
	if (force_exit)
		exit(1);
}
