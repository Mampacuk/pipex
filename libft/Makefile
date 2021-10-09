# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 17:06:08 by aisraely          #+#    #+#              #
#    Updated: 2021/10/09 16:53:36 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(shell find "." -name "*.c" ! -name "ft_lst*.c")
BONUSES		= $(shell find "." -name "*.c")
OBJS		= ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUSES:.c=.o}
NAME		= libft.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
AR			= ar csr

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@${AR} ${NAME} ${OBJS}

bonus: ${BONUS_OBJS}
	@${AR} ${NAME} ${BONUS_OBJS}

all: ${NAME}

clean:
	@${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean bonus re .c.o