# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 09:37:12 by jael-mor          #+#    #+#              #
#    Updated: 2023/03/26 22:24:07 by jael-mor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = pipex.h
SRCS = pipex.c \
			child_processes.c \
			executing_commands.c \
			utils.c \
			utils2.c \
			utils3.c \
			
OBJ = ${SRCS:.c=.o}

all: ${NAME}
${NAME}: ${OBJ} ${HEADER}
		${CC} ${FLAGS} ${OBJ} -o ${NAME}
%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

clean: 
		rm -f ${OBJ}
fclean: clean
		rm -f $(NAME)
re: fclean all
.PHONY = all clean fclean re