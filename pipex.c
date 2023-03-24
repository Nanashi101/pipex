/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:06:43 by jael-mor          #+#    #+#             */
/*   Updated: 2023/03/24 09:16:19 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

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

char	**get_env_path( char **envp, j_dtin *pp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (strnstr(envp[i], "PATH", 5))
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
	// void	lk(void)
	// {
	// 	system("leaks pipex");
	// }

int	main(int ac, char **av, char **envp)
{
	j_dtin	pp;
	//atexit(lk);
	pp.infile_fd = open(av[1], O_RDONLY | O_CREAT, 0777);
	pp.outfile_fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (pp.infile_fd < 0 || pp.outfile_fd < 0)
	{
		perror("Failed to open files");
		exit(0);
	}
	if (pipe(pp.end))
	{
		perror("Pipe failed");
		exit(0);
	}
	child_process1(&pp, av, envp);
	child_process2(&pp, av, envp);
	wait(NULL);
	//free_all(envp);
	return (0);
}
