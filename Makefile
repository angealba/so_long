NAME = so_long

SRC = so_long.c map.c map_errors.c errors_utils.c get_next_line.c get_next_line_utils.c routes_check.c graphics.c controls.c

LIBRARY = -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC:.c=.o)

INCLUDE = so_long.h get_next_line.h

CC = gcc
FLAGS = -Wall -Werror -Wextra -Iheaders -g3 -fsanitize=address

all: $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
		@$(CC) $(SRC) $(LIBRARY) -o $(NAME)
		@echo "\n $(NAME) created"

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)
		@echo "\n All objects cleaned succesfully"

fclean: 
	rm -f $(NAME)
	@echo "\n All objects and executable cleaned succesfully"

re: fclean all

.PHONY: all, clean, fclean, re