NAME = minishell
# CC=gcc
# CFLAGS=-Wall -Wextra -Werror -ggdb3
CC=cc
CFLAGS=-Wall -Wextra -Werror
INC_DIR = includes
IFLAGS = -I$(INC_DIR)
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a
SRC_DIR = src
SOURCES= \
$(SRC_DIR)/.c 

all: $(NAME)

OBJECTS = $(SOURCES:.c=.o)

$(NAME) : $(OBJECTS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJECTS) $(LIBFT_A) -o $(NAME) 

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re