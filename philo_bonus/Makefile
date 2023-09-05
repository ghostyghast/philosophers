DIR = src/

SRCS = $(wildcard $(addprefix $(DIR), *.c))

OBJ = $(SRCS:.c=.o)

NAME = philo_bonus

INCLUDES = -Iincludes

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ)

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	@rm -rf $(DIR)*.o

fclean : clean
	@rm $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re