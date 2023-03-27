/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:06:43 by jael-mor          #+#    #+#             */
/*   Updated: 2023/03/26 03:12:50 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_cmd_path(char **fullpath, char *path)
{
	int	i;

	i = 0;
	if (access(path, X_OK) == 0)
		return (path);
	path = ft_strjoin("/", path);
	while (fullpath[i])
	{
		fullpath[i] = ft_strjoin(fullpath[i], path);
		if (access(fullpath[i], X_OK) == 0)
			return (fullpath[i]);
		i++;
	}
	return (NULL);
}

char	**get_env_path( char **envp, t_dtin *pp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 5))
			break ;
		i++;
	}
	if (envp[i])
	{
		pp->path_name = envp[i] + 5;
		pp->full_path = ft_split(pp->path_name, ':');
		return (pp->full_path);
	}
	return (NULL);
}

int	main(int ac, char **av, char **envp)
{
	t_dtin	pp;

	if (ac == 5)
	{
		pp.infile_fd = open(av[1], O_RDWR, 0777);
		pp.outfile_fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (pp.infile_fd < 0 || pp.outfile_fd < 0)
		{
			write(2, "no such file or directory : ", 28);
			write(2, av[1], ft_strlen(av[1]));
			write(2, "\n", 1);
			exit(1);
		}
		if (pipe(pp.end) < 0)
		{
			perror("Pipe failed");
			exit(1);
		}
		child_process1(&pp, av, envp);
		child_process2(&pp, av, envp);
		wait(NULL);
		return (0);
	}
	return (write(2, "Invaid number of arguments", 25), 0);
}
