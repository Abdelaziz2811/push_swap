NAME = push_swap
BONUS_NAME = checker
SRCS_DIR = srcs
BONUS_SRCS_DIR = bonus/srcs
GNL_DIR = bonus/gnl
OPERS_DIR = $(SRCS_DIR)/operations
STACK_DIR = $(SRCS_DIR)/stack
INC = includes
BONUS_INC = bonus/includes
GNL_INC = bonus/gnl

SRCS = $(SRCS_DIR)/push_swap.c $(SRCS_DIR)/parser.c $(SRCS_DIR)/utils.c \
	   $(OPERS_DIR)/push.c $(OPERS_DIR)/rotate.c $(OPERS_DIR)/rrotate.c $(OPERS_DIR)/swap.c \
	   $(STACK_DIR)/stack.c $(STACK_DIR)/push_back.c $(STACK_DIR)/small_sort.c $(STACK_DIR)/stack_a_data.c \
	   $(STACK_DIR)/stack_b_data.c $(STACK_DIR)/sort_helpers.c $(STACK_DIR)/sort_stacks.c
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = $(SRCS_DIR)/parser.c $(SRCS_DIR)/utils.c \
			 $(OPERS_DIR)/push.c $(OPERS_DIR)/rotate.c $(OPERS_DIR)/rrotate.c $(OPERS_DIR)/swap.c \
			 $(STACK_DIR)/stack.c $(STACK_DIR)/push_back.c \
			 $(BONUS_SRCS_DIR)/checker_bonus.c \
			 $(BONUS_SRCS_DIR)/process_operations.c $(BONUS_SRCS_DIR)/execute_operations.c \
			 $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

FT_PRINTF_DIR = ft_printf
FT_PRINTF = libftprintf.a
FT_PRINTF_PATH = $(FT_PRINTF_DIR)/$(FT_PRINTF)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(FT_PRINTF_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_PATH) -o $(NAME)

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(FT_PRINTF_PATH) :
	make -C $(FT_PRINTF_DIR)

bonus : $(FT_PRINTF_PATH) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(FT_PRINTF_PATH) -o $(BONUS_NAME)

$(BONUS_SRCS_DIR)/%.o : $(BONUS_SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I $(BONUS_INC) -c $< -o $@

$(GNL_DIR)/%.o : $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -I $(GNL_INC) -c $< -o $@

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)
	make -C $(FT_PRINTF_DIR) clean

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)
	make -C $(FT_PRINTF_DIR) fclean

re : fclean all

.PHONY : all clean fclean re