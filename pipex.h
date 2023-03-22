/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:19 by jael-mor          #+#    #+#             */
/*   Updated: 2023/03/22 18:59:56 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

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




