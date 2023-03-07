/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:47:02 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/07 15:03:55 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	pipex = (t_pipex){};
	(void)argc;
	(void)argv;
	init_path(env, &pipex);
	free_and_exit(&pipex, 0);
	return (0);
}
