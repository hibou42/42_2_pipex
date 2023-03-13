/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:02:00 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/07 14:49:12 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	is_valid_cmd(t_pipex *pipex, char *cmd)
{
	char	*tmp;
	char	*tmp_add_slash;
	int		ret;
	int		i;

	i = 0;
	while(pipex->path[i])
	{
		tmp_add_slash = ft_strjoin(pipex->path[i], "/");
		tmp = ft_strjoin(tmp_add_slash, cmd);
		ret = access(tmp, X_OK);
		if (ret == 0)
			pipex->cmd_path = ft_strtrim(tmp, "");
		free(tmp_add_slash);
		free(tmp);
		i++;
	}
}
