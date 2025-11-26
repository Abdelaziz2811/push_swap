NAME = push_swap
SRCS_DIR = srcs
OPERS_DIR = $(SRCS_DIR)/operations
STACK_DIR = $(SRCS_DIR)/stack
INC = includes

SRCS = $(SRCS_DIR)/push_swap.c $(SRCS_DIR)/push_swap_utils.c \
	   $(OPERS_DIR)/push.c $(OPERS_DIR)/rotate.c $(OPERS_DIR)/rrotate.c $(OPERS_DIR)/swap.c \
	   $(STACK_DIR)/stack.c $(STACK_DIR)/push_back.c $(STACK_DIR)/small_sort.c
OBJS = $(SRCS:.c=.o)

FT_PRINTF_DIR = ft_printf
FT_PRINTF = libftprintf.a
FT_PRINTF_PATH = $(FT_PRINTF_DIR)/$(FT_PRINTF)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(FT_PRINTF_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(FT_PRINTF_PATH) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(FT_PRINTF_PATH) :
	make -C $(FT_PRINTF_DIR)

clean :
	rm -rf $(OBJS)
	make -C $(FT_PRINTF_DIR) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(FT_PRINTF_DIR) fclean

re : fclean all

.PHONY : all clean fclean re