/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:50:25 by aschaefe          #+#    #+#             */
/*   Updated: 2023/03/31 14:52:53 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"

typedef struct s_pipex
{
	char	**path;
	char	*cmd_path;
	char	**tab_cmd;
	int		pid[2];
	int		tab_fd[2];
	int		fd_in;
	int		fd_out;
}					t_pipex;

void	check_arg(int argc, char **argv, t_pipex *pipex);
void	init_path(char **env, t_pipex *pipex);
void	free_and_exit(t_pipex *pipex, int force_exit);
int		is_valid_cmd(t_pipex *pipex);
void	exec_cmd(t_pipex *pipex, char **env);
void	fd_open(char **argv, t_pipex *pipex);
void	fd_close(t_pipex *pipex);
void	init_pipe(t_pipex *pipex);
void	error(t_pipex *pipex, char *msg);
void	time_to_fork(t_pipex *pipex, char **argv, char **env);
void	child_process(t_pipex *pipex, char **argv, char **env);
void	child2_process(t_pipex *pipex, char **argv, char **env);

#endif