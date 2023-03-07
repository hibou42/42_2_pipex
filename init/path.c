/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:02:00 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/07 14:49:12 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_path(char **env, t_pipex *pipex)
{
	char	*tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A')
		{
			if (env[i][2] == 'T' && env[i][3] == 'H')
			{
				tmp = ft_strtrim(env[i], "PATH=");
				pipex->path = ft_split(tmp, ':');
				free(tmp);
			}
		}
		i++;
	}
}
