CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
SRC = main.c  push.c rev_retate.c retate.c swap.c chunks.c chunks2.c chunks3.c
SRC_SHARED =  utils.c utils2.c utils3.c sort.c initialisation.c push_split.c check.c move.c utils4.c
SRC_B = bonnus/main_bonus.c bonnus/get_next_line.c bonnus/get_next_line_utils.c bonnus/swap_b.c bonnus/push_b.c bonnus/retat_b.c bonnus/rev_retat_b.c

OBJ = $(SRC:.c=.o)
OBJ_SHARED = $(SRC_SHARED:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

NAME = push_swap
NAME_B = checker


GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m


all : $(NAME)

$(NAME) : $(OBJ) $(OBJ_SHARED)
	$(CC) $(CFLAGS) $(SRC) $(SRC_SHARED) -o $(NAME)
	@echo "$(YELLOW)I did compile -~-$(RESET)"

debug : CFLAGS += -g3
debug : re

bonus : $(NAME_B)

$(NAME_B) : $(OBJ_B) $(OBJ_SHARED)
	$(CC) $(CFLAGS) $(SRC_B) $(SRC_SHARED) -o $(NAME_B)
	@echo "$(YELLOW)bonus compiled $(RESET)"

clean :
	rm -f $(OBJ) $(OBJ_B) $(OBJ_SHARED)
	@echo "$(GREEN)cleaned... $(RESET)"
fclean : clean
	@echo "$(GREEN)more clean... $(RESET)"
	rm -f $(NAME) $(NAME_B)
re : fclean all
	@echo "$(RED)recompiling... $(RESET)"
.PHONY: re all clean bonus
.SECONDARY: $(OBJ) $(OBJ_B) $(OBJ_SHARED)