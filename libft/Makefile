NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

SRC = $(wildcard ft_i*.c) $(wildcard ft_mem*.c) $(wildcard ft_put*.c) \
  $(wildcard ft_s*.c) $(wildcard ft_to*.c) ft_atoi.c ft_bzero.c ft_calloc.c ft_exit.c ft_charmatrixlen.c ft_freecharmatrix.c
OBJ = $(SRC:.c=.o)
BONUS = $(wildcard ft_lst*.c)
BONUS_OBJ = $(BONUS:.c=.o)


$(NAME): 
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

bonus:
	@$(CC) $(CFLAGS) -c $(BONUS) $(SRC)
	@$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)

fclean:  clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus 