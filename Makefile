# ======= VARIABLES =======
NAME = 
CFLAGS = -Wall -Wextra -Werror
# ======= FILES =======

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

clean:
	@make -C libft/ clean
	@rm -rf $(OBJS)
	@echo "$(WHITE)Objects deleted.$(RESET)"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "$(PURPLE)$(NAME) removed.$(RESET)"

norm:
	@echo "$(YELLOW)Running norminette...$(RESET)"
	@norminette
	@echo "$(YELLOW)All OK.$(RESET)"

.PHONY: clean fclean norm