/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:02:00 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/31 15:51:10 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	is_valid_cmd(t_pipex *pipex)
{
	char	*tmp;
	char	*tmp_add_slash;
	int		i;

	i = 0;
	while (pipex->path[i])
	{
		tmp_add_slash = ft_strjoin(pipex->path[i], "/");
		tmp = ft_strjoin(tmp_add_slash, pipex->tab_cmd[0]);
		if (!tmp)
			error(pipex, "error from strjoin", NULL);
		if (access(tmp, F_OK) == 0)
		{
			pipex->cmd_path = tmp;
			free(tmp_add_slash);
			break ;
		}
		free(tmp_add_slash);
		free(tmp);
		i++;
	}
	if (!pipex->cmd_path)
		return (1);
	return (0);
}
