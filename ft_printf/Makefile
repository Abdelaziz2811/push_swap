NAME = libftprintf.a
SRCS_DIR = srcs
INC = includes

SRCS = $(SRCS_DIR)/ft_printf.c $(SRCS_DIR)/ft_print_char.c $(SRCS_DIR)/ft_print_str.c \
	   $(SRCS_DIR)/ft_print_ptr.c $(SRCS_DIR)/ft_print_int.c $(SRCS_DIR)/ft_print_uint.c \
	   $(SRCS_DIR)/ft_print_hex_low.c $(SRCS_DIR)/ft_print_hex_upp.c $(SRCS_DIR)/ft_print_char_fd.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_INC = $(LIBFT_DIR)/includes
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(LIBFT_PATH) $(OBJS)
	cp $(LIBFT_PATH) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT_PATH) :
	make -C $(LIBFT_DIR)
	make -C $(LIBFT_DIR) bonus

%.o : %.c $(INC)/ft_printf.h
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean :
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re