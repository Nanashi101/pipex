/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:11:29 by jael-mor          #+#    #+#             */
/*   Updated: 2023/03/26 22:24:42 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(t_dtin *pp, char **av, char **envp)
{
	pp->pid1 = fork();
	if (pp->pid1 < 0)
	{
		perror("fork failed");
		exit(0);
	}
	if (pp->pid1 == 0)
	{
		if (dup2(pp->infile_fd, STDIN_FILENO) < 0
			|| dup2(pp->end[1], STDOUT_FILENO) < 0)
		{
			perror("dup2 infile or end[1] failed");
		}
		close(pp->end[0]);
		close(pp->infile_fd);
		envp = get_env_path(envp, pp);
		if (envp == NULL)
		{
			perror("path couldn't found");
		}
		executing_cmd1(av, pp, envp);
		close(pp->end[1]);
	}
}

void	child_process2(t_dtin *pp, char **av, char**envp)
{
	pp->pid2 = fork();
	if (pp->pid2 < 0)
	{
		perror("fork failed");
	}
	if (pp->pid2 == 0)
	{
		if (dup2(pp->outfile_fd, STDOUT_FILENO) < 0
			|| dup2(pp->end[0], STDIN_FILENO) < 0)
		{
			perror("dup2 outfile or end[0] failed");
			exit(1);
		}
		close(pp->end[1]);
		close(pp->outfile_fd);
		envp = get_env_path(envp, pp);
		if (envp == NULL)
			perror("path couldn't found");
		executing_cmd2(av, pp, envp);
		close(pp->end[0]);
	}
}
