/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:13:15 by jael-mor          #+#    #+#             */
/*   Updated: 2023/03/24 09:13:26 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	executing_cmd1(char **av, j_dtin *pp, char **envp)
{
	pp->cmd1 = ft_split(av[2], ' ');
	pp->cmdpath = check_cmd_path(envp, pp->cmd1[0]);
	if (pp->cmdpath == NULL)
	{
		perror("Command not found");
		exit (1);
	}
	if (execve(pp->cmdpath, pp->cmd1, NULL) == -1)
	{
		perror("Exec cmd1 Error");
		exit(1);
	}
}

void	executing_cmd2(char **av, j_dtin *pp, char **envp)
{
	pp->cmd2 = ft_split(av[3], ' ');
	pp->cmdpath = check_cmd_path(envp, pp->cmd2[0]);
	if (pp->cmdpath == NULL)
	{
		perror("Command not found");
		exit (1);
	}
	if (execve(pp->cmdpath, pp->cmd2, NULL) == -1)
	{
		perror("Exec cmd2 Error");
		exit (1);
	}
}