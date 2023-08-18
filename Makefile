DIR = src/

SRCS = $(wildcard $(addprefix $(DIR), *.c))

OBJ = $(SRCS:.c=.o)

NAME = philosophers

INCLUDES = -Iincludes -Ilibft -L./libft -lft

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ)

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) -Iincludes -Ilibft -c $< -o $@

clean :
	@make clean -C ./libft
	@rm -rf $(DIR)*.o

fclean : clean
	@make fclean -C ./libft
	@rm $(NAME)

re : fclean all
	@make re -C ./libft

.PHONY: all bonus clean fclean re