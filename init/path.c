/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:02:00 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/31 14:09:24 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_path(char **env, t_pipex *pipex)
{
	char	*tmp;
	int		ret_cmp;
	int		i;

	i = 0;
	while (env[i])
	{
		ret_cmp = ft_strncmp(env[i], "PATH=", 5);
		if (ret_cmp == 0)
		{
			tmp = ft_strtrim(env[i], "PATH=");
			pipex->path = ft_split(tmp, ':');
			free(tmp);
		}
		i++;
	}
	if (pipex->path == NULL)
		error(pipex, "error path not found");
}
