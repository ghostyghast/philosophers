SRCS = $(wildcard *.c)

# SRC_PREF = $(addprefix src/, $(SRCS))

OBJ = $(SRCS:.c=.o)

NAME = philosophers

INCLUDES = -Iincludes -Ilibft -L./libft -lft

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ)

%.o: %.c 
	$(CC) $(CFLAGS) -Iincludes -Ilibft -c $< -o $@

clean :
	@make clean -C ./libft
	@rm -rf src/*.o

fclean : clean
	@make fclean -C ./libft
	@rm $(NAME) $(BONUS)

re : fclean all
	@make re -C ./libft

.PHONY: all bonus clean fclean re