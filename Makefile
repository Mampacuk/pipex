# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 13:19:31 by aisraely          #+#    #+#              #
#    Updated: 2021/10/09 16:58:32 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS	= ${wildcard *.c}
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@$(MAKE) -C ./libft
	@${CC} ${OBJS} ${CFLAGS} ./libft/libft.a -o ${NAME}

clean:
	@$(MAKE) -C libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

bonus: all

.PHONY: clean fclean re all bonus