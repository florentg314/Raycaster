SRC	=	src/main.c \
		src/parser.c \
		src/move_player.c \
		src/create_player.c \
		src/math.c

OBJ	=	$(SRC:.c=.o)

NAME	=	raycaster

CFLAGS	=	-Wall -Wextra -pedantic -g

CSFML_FLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML_FLAGS) -lm -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
