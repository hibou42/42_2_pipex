/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:51:21 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/31 15:50:57 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	fd_close(t_pipex *pipex)
{
	if (close(pipex->tab_fd[0]) < 0)
		error(pipex, "error closing fd", NULL);
	if (close(pipex->tab_fd[1]) < 0)
		error(pipex, "error closing fd", NULL);
}
