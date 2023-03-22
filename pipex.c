/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:06:43 by jael-mor          #+#    #+#             */
/*   Updated: 2023/03/22 22:25:34 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *check_cmd_path(char **fullpath, char *path)
{
    int i;
    
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

void   executing_cmd1(char **av, j_dtin *pp, char **envp)
{
    pp->cmd1 = ft_split(av[2], ' ');
    pp->cmdpath = check_cmd_path(envp, pp->cmd1[0]);
    if (pp->cmdpath == NULL)
	{
		perror("Command not found");
		exit (1);
	}
    if (execve(pp->cmdpath, pp->cmd1, NULL) == -1)
		perror("Error");
    
}

void   executing_cmd2(char **av, j_dtin *pp, char **envp)
{
    pp->cmd2 = ft_split(av[3], ' ');
    pp->cmdpath = check_cmd_path(envp, pp->cmd2[0]);
    if (pp->cmdpath == NULL)
	{
		perror("Command not found");
		exit (1);
	}
    if (execve(pp->cmdpath, pp->cmd2, NULL) == -1)
		perror("Error");
    
}

char    **get_env_path( char **envp, j_dtin *pp)
{
	int		i;

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

int main(int ac, char **av, char **envp)
{
    j_dtin pp;
    
    pp.infile_fd = open(av[1], O_RDONLY | O_CREAT, 0777);
    pp.outfile_fd = open(av[4], O_CREAT | O_RDWR, 0777);
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
    if ((pp.pid1 = fork()) < 0)
    {
        perror("fork failed");
        exit(0);
    }
    if (pp.pid1 == 0)
    {
        if(dup2(pp.infile_fd, STDIN_FILENO) < 0 || dup2(pp.end[1], STDOUT_FILENO) < 0)
        {
            perror("dup2 infile or end[0] failed");
            exit(0);        
        }
        close(pp.end[0]);
        close(pp.infile_fd);
        envp = get_env_path(envp, &pp);
        if (envp == NULL)
            perror("path couldn't found");
        executing_cmd1(av, &pp, envp);        
        
    }
    waitpid(pp.pid1,NULL,0);
    if ((pp.pid2 = fork()) < 0)
    {
        perror("fork failed");
        exit(0);
    }
    if (pp.pid2 == 0)
    {
        if(dup2(pp.outfile_fd, STDOUT_FILENO) < 0 || dup2(pp.end[0], STDIN_FILENO) < 0)
        {
            perror("dup2 infile or end[0] failed");
            exit(0);        
        }
        close(pp.end[1]);
        close(pp.outfile_fd);
        envp = get_env_path(envp, &pp);
        if (envp == NULL)
            perror("path couldn't found");
        executing_cmd1(av, &pp, envp); 
               
        
    }
    waitpid(pp.pid2,NULL,0);
    return (0);
}