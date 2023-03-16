/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:33:59 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/16 12:55:31 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_fd(t_pipex *pipex, char **argv)
{
	pipex->fd_in = open(argv[1], O_RDONLY);
	dup2(pipex->fd_in, 0);
	close(pipex->fd_in);
}
