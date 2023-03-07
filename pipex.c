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

void	test_print(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->path[i])
	{
		ft_printf("%s\n", pipex->path[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	pipex = (t_pipex){};
	(void)argc;
	(void)argv;
	init_path(env, &pipex);
	test_print(&pipex);
	int fd = access("/bin/ls", R_OK & W_OK & X_OK & F_OK);
	printf("if 0 = it s gooooood, -1 = does not exist --> %d\n",fd);
	free_and_exit(&pipex, 0);
	return (0);
}
