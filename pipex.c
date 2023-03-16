/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:47:02 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/16 12:55:18 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

//test_print(&pipex);
void	test_print(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->tab_cmd[i])
	{
		ft_printf("%s\n", pipex->path[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	pipex = (t_pipex){};
	init_path(env, &pipex);
	check_arg(argc, argv, &pipex);
	//creer le pipe
	//fork
	//if fork == 0 (c est que t es dans child)
	is_valid_cmd(&pipex, argv[2]);
	init_tab_cmd(&pipex, argv[2]);
	open_fd(&pipex, argv);
	exec_cmd(&pipex, env);
	free_and_exit(&pipex, 0);
	return (0);
}

/*
Step 1 : Check si commande valable (acces)
Step 2 : Executer la fameuse commande avec execve
Step 3 : Rediriger la sortie de la commande dans un FD
Step 4 : Tous faire dans un fork
Step 5 : Faire 2 commandes
Step 6 : Faire communiquer les deux commande via le Pipe

best tuto : https://github.com/widium/pipex

	int		fd;
	fd = open(argv[1], O_RDONLY);
*/
