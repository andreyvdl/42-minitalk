# ======= VARIABLES =======
S_NAME = server
C_NAME = client
CFLAGS = -Wall -Wextra -Werror -g3
# ======= FILES =======
S_FILES = server.c
S_OBJS = $(S_FILES:%.c=%.o)
C_FILES = client.c
C_OBJS = $(C_FILES:%.c=%.o)
# ======= COLORS ========
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
RESET = \033[0m
# ======= RULES =======

all: lib
	@make $(S_NAME)
	@make $(C_NAME)

$(C_NAME): $(C_OBJS)
	@echo "$(GREEN)Compiling $(C_NAME)...$(RESET)"
	@cc $(CFLAGS) $(C_OBJS) libft/libft.a -o $(C_NAME)
	@echo "$(GREEN)$(C_NAME) created.$(RESET)"

$(C_OBJS):
	@cc $(CFLAGS) -c $(@:.o=.c)

$(S_NAME): $(S_OBJS)
	@echo "$(GREEN)Compiling $(S_NAME)...$(RESET)"
	@cc $(CFLAGS) $(S_OBJS) libft/libft.a -o $(S_NAME)
	@echo "$(GREEN)$(S_NAME) created.$(RESET)"

$(S_OBJS):
	@cc $(CFLAGS) -c $(@:.o=.c)

bonus:
	@make C_FILES="$(C_BONUS)" S_FILES="$(S_BONUS)" --no-print-directory

lib:
	@make -C libft/

clean:
	@make clean -C libft/
	@rm -rf $(C_OBJS) $(S_OBJS)
	@echo "$(WHITE)Objects deleted.$(RESET)"

fclean: clean
	@make fclean -C libft/
	@rm -rf $(C_NAME) $(S_NAME)
	@echo "$(PURPLE)$(S_NAME) && $(C_NAME) removed.$(RESET)"

re : fclean all

norm:
	@echo "$(YELLOW)Running norminette...$(RESET)"
	@norminette
	@echo "$(YELLOW)All OK.$(RESET)"

.PHONY: all clean fclean re norm lib 