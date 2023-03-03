/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:47:02 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/03 15:08:17 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	test_print_env(char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			ft_printf("%c", env[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	pipex = (t_pipex){};
	(void)argc;
	(void)argv;
	test_print_env(env);
	return (0);
}
