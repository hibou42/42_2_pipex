/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:06:41 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/16 18:20:04 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parent_process(t_pipex *pipex, char **argv, char **env)
{
	is_valid_cmd(pipex, argv[3]);
	init_tab_cmd(pipex, argv[3]);
	open_fd(pipex, argv);
	exec_cmd(pipex, env);
}
