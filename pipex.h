/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:19 by jael-mor          #+#    #+#             */
/*   Updated: 2023/03/24 09:13:55 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
 #include <sys/wait.h>
      #include <string.h> 
typedef struct i_dtin
{
    pid_t   pid1;
    pid_t   pid2;
    int     end[2];
    int     outfile_fd;
    int     infile_fd;
    char    *path_name;
    char    **full_path;
    char    **cmd1;
    char    **cmd2;
    char    *cmdpath;
}               j_dtin;

#endif


char	**ft_split(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(char const *str);
void	child_process2(j_dtin *pp, char **av, char**envp);
void	child_process1(j_dtin *pp, char **av, char **envp);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	executing_cmd1(char **av, j_dtin *pp, char **envp);
void	executing_cmd2(char **av, j_dtin *pp, char **envp);



