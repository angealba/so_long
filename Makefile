DEF_COLOR =		\033[0;39m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_YELLOW =	\033[38;5;143m
DARK_GREEN =	\033[38;2;75;179;82m

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
		@echo "\n$(DARK_GREEN)$(NAME) created ✓$(DEF_COLOR)\n"

%.o : %.c
	@echo "$(DARK_YELLOW)Compiling  ${ORANGE}→  $(DARK_GREEN)$< $(DEF_COLOR)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
		@rm -f $(OBJ)
		@echo "\n$(BROWN)All objects cleaned successfully$(DEF_COLOR)\n"

fclean: 
		@rm -f $(OBJ)
		@rm -f $(NAME)
		@echo "\n$(BROWN)All objects and executable cleaned successfully$(DEF_COLOR)\n"

re: fclean all

.PHONY: all, clean, fclean, re