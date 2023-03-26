/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:02:00 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/16 12:29:35 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	is_valid_cmd(t_pipex *pipex)
{
	char	*tmp;
	char	*tmp_add_slash;
	int		i;

	i = 0;
	while (pipex->path[i])
	{
		tmp_add_slash = ft_strjoin(pipex->path[i], "/");
		tmp = ft_strjoin(tmp_add_slash, pipex->tab_cmd[0]);
		if (access(tmp, F_OK) == 0)
			pipex->cmd_path = ft_strtrim(tmp, "");
		free(tmp_add_slash);
		free(tmp);
		i++;
	}
}