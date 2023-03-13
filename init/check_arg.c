/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:38:51 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/07 14:50:56 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_arg(int argc, char **argv, t_pipex *pipex)
{
	(void)argv;
	if (argc != 2)
	{
		ft_printf("Error\nNombre d'argument pas bon\n");
		free_and_exit(pipex, 1);
	}
}
