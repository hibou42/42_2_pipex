/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:50:25 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/07 14:42:31 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"

typedef struct s_pipex
{
	char	**path;
}					t_pipex;

void	init_path(char **env, t_pipex *pipex);
void	free_and_exit(t_pipex *pipex, int force_exit);

#endif