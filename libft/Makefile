# ======= VARIABLES =======
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
# ======= FILES =======
LIB_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c \
	ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_printf.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	ft_substr.c ft_tolower.c ft_toupper.c gnl_utils.c gnl.c \
	hex_handler.c nbr_handler.c
LIB_OBJS = $(LIB_SRCS:%.c=%.o)
# ======= COLORS ========
BLACK =		\033[1;30m
RED =		\033[1;31m
GREEN =		\033[1;32m
YELLOW =	\033[1;33m
BLUE =		\033[1;34m
PURPLE =	\033[1;35m
CYAN =		\033[1;36m
WHITE =		\033[1;37m
RESET =		\033[0m
# ======= RULES =======

all:		$(NAME)

$(NAME):	$(LIB_OBJS)
	@echo "$(GREEN)Creating $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(LIB_OBJS)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(LIB_OBJS):
	@cc $(CFLAGS) -I . -c $(@:%.o=%.c)

clean:
	@rm -rf $(LIB_OBJS)
	@echo "$(WHITE)Objects deleted.$(RESET)"

fclean:		clean
	@rm -rf $(NAME)
	@echo "$(PURPLE)$(NAME) removed.$(RESET)"

re:			fclean all
	@echo "$(RED)Recompilation completed.$(RESET)"

norm:
	@echo "$(YELLOW)Running norminette...$(RESET)"
	@norminette
	@echo "$(YELLOW)All OK.$(RESET)"

.PHONY:		all clean fclean re norm