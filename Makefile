NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

LIBFT = libft/libft.a

SRC = push_swap.c ft_error.c ft_list.c ft_index.c rotate.c swap.c push.c maxminindex.c sort.c radix.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		make -C ./libft -s
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
		make clean -C ./libft
		$(RM) $(OBJ)

fclean: clean
		make fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re