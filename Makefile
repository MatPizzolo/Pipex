NAME = pipex
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)/libft.h
SRCS_DIR = ./src

SRCS = $(SRCS_DIR)/pipex.c $(SRCS_DIR)/utils.c $(SRCS_DIR)/get_path.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS =

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(LIBFT_INC)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
