/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:10:58 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/28 16:53:51 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error(t_pipex *pipex, char *msg)
{
	ft_printf("%s\n", msg);
	free_and_exit(pipex, 1);
}

/* before insteed of ft_printf
	perror(msg);
*/