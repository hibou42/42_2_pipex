/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:46:36 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/28 16:10:41 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	fd_open(char **argv, t_pipex *pipex)
{
	pipex->fd_in = open(argv[1], O_RDONLY);
	pipex->fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (pipex->fd_in < 0 || pipex->fd_out < 0)
		error(pipex, "Open error");
}
