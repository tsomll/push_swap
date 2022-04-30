NAME		=	push_swap
NAME2		=	checker

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

BONUS_DIR	=	./bonus/
HEADER_DIR	=	./includes/
SOURCES_DIR	=	./sources/
UTILS_DIR	=	./utils/
LIBFT		=	-L ./sources/libft -lft

SRCS		=	$(addprefix $(SOURCES_DIR), begin_sort.c	big_sort.c	prepare_to_sort.c	push_swap.c)
UTILS		=	$(addprefix $(UTILS_DIR),	check.c			error_msg.c	list_utils.c		list_utils2.c\
											list_utils3.c	stack_operation.c)
HEADER		=	$(addprefix $(HEADER_DIR),	push_swap.h)
BONUS		=	$(addprefix $(BONUS_DIR),	checker.c)

OBJS		=	$(SRCS:%.c=%.o)		$(UTILS:%.c=%.o)
OBJS2		=	$(BONUS:%.c=%.o)	$(UTILS:%.c=%.o)

WHITE		=	\033[0m
BLACK		=	\033[0;30m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
MAGENTA		=	\033[0;35m
CYAN		=	\033[0;36m

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)
bonus		:	$(NAME2)

$(NAME)		:	$(OBJS)
				@make -C ./sources/libft
				@echo " \n[$(BLUE)PUSH_SWAP$(WHITE)] OBJECT FILE CREATED\n\c"
				@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
				@echo "[$(BLUE)PUSH_SWAP$(WHITE)] EXECUTABLE FILE CREATED\n\c"
				@afplay ./sound/all.mp3 &
$(NAME2)	:	$(OBJS2)
				@make -C ./sources/libft
				@echo "\n[$(BLUE)CHECKER$(WHITE)] OBJECT FILE CREATED\n\c"
				@$(CC) $(CFLAGS) $(LIBFT) $(OBJS2) -o $(NAME2)
				@echo "[$(BLUE)CHECKER$(WHITE)] EXECUTABLE FILE CREATED\n\c"
				@afplay ./sound/all.mp3 &

%.o			:	%.c $(HEADER)
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "$(GREEN)❱❱❱$(WHITE)\c"

clean		:
				@make -C ./sources/libft clean
				@$(RM) $(OBJS) $(OBJS2)
				@echo "$(RED)OBJECT FILES DELETED$(WHITE)\n\c"

fclean		:	clean
				@make -C ./sources/libft fclean
				@$(RM) $(NAME) $(NAME2)
				@echo "$(RED)EXECUTABLE FILES DELETED$(WHITE)\n\c"
				@afplay ./sound/fclean.mp3 &

re			:	fclean all bonus