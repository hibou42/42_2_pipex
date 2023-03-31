/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:10:58 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/31 15:55:31 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error(t_pipex *pipex, char *msg, char *msg2)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(msg, 2);
	if (msg2)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg2, 2);
	}
	ft_putstr_fd("\n", 2);
	free_and_exit(pipex, 1);
}
