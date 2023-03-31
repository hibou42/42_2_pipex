/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:51:21 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/31 14:52:35 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	fd_close(t_pipex *pipex)
{
	if (close(pipex->tab_fd[0]) < 0)
		error(pipex, "error closing fd");
	if (close(pipex->tab_fd[1]) < 0)
		error(pipex, "error closing fd");
}
