NAME = libft.a

INC_DIR = includes
SRC_DIR = src
CHAR_DIR = $(SRC_DIR)/char
CONV_DIR = $(SRC_DIR)/conversion
IO_DIR = $(SRC_DIR)/io
MEMORY_DIR = $(SRC_DIR)/memory
NUMBER_DIR = $(SRC_DIR)/number
LIST_DIR = $(SRC_DIR)/lists
STRING_DIR = $(SRC_DIR)/string

SOURCES = \
$(CHAR_DIR)/ft_isalnum.c \
$(CHAR_DIR)/ft_isalpha.c \
$(CHAR_DIR)/ft_isascii.c \
$(CHAR_DIR)/ft_isdigit.c \
$(CHAR_DIR)/ft_isprint.c \
$(CHAR_DIR)/ft_isspace.c \
$(CHAR_DIR)/ft_tolower.c \
$(CHAR_DIR)/ft_toupper.c \
$(CONV_DIR)/ft_atoi.c \
$(CONV_DIR)/ft_itoa.c \
$(CONV_DIR)/ft_atoi_arr.c \
$(CONV_DIR)/ft_atoi_arr.c \
$(IO_DIR)/ft_printf_basic.c \
$(IO_DIR)/ft_printf.c \
$(IO_DIR)/ft_printf_hard.c \
$(IO_DIR)/ft_putchar_fd.c \
$(IO_DIR)/ft_putendl_fd.c \
$(IO_DIR)/ft_putlong_base.c \
$(IO_DIR)/ft_putnbr_base.c \
$(IO_DIR)/ft_putunbr_base.c \
$(IO_DIR)/ft_putnbr_fd.c \
$(IO_DIR)/ft_putstr_fd.c \
$(IO_DIR)/ft_putunbr.c \
$(IO_DIR)/get_next_line.c \
$(IO_DIR)/get_next_line_utils.c \
$(LIST_DIR)/ft_lstadd_back.c \
$(LIST_DIR)/ft_lstadd_front.c \
$(LIST_DIR)/ft_lstclear.c \
$(LIST_DIR)/ft_lstdelone.c \
$(LIST_DIR)/ft_lstiter.c \
$(LIST_DIR)/ft_lstlast.c \
$(LIST_DIR)/ft_lstmap.c \
$(LIST_DIR)/ft_lstnew.c \
$(LIST_DIR)/ft_lstsize.c \
$(MEMORY_DIR)/ft_bzero.c \
$(MEMORY_DIR)/ft_calloc.c \
$(MEMORY_DIR)/ft_memchr.c \
$(MEMORY_DIR)/ft_memcmp.c \
$(MEMORY_DIR)/ft_memcpy.c \
$(MEMORY_DIR)/ft_memmove.c \
$(MEMORY_DIR)/ft_memset.c \
$(MEMORY_DIR)/ft_realloc.c \
$(MEMORY_DIR)/ft_free_str_arr.c \
$(MEMORY_DIR)/ft_free_int_arr.c \
$(MEMORY_DIR)/ft_free_3d_arr.c \
$(NUMBER_DIR)/ft_abs_diff.c \
$(NUMBER_DIR)/ft_intdup.c \
$(NUMBER_DIR)/ft_intlen.c \
$(NUMBER_DIR)/ft_sort_int_tab.c \
$(NUMBER_DIR)/ft_swap.c \
$(NUMBER_DIR)/ft_valid_int.c \
$(STRING_DIR)/ft_count_char.c \
$(STRING_DIR)/ft_count_words.c \
$(STRING_DIR)/ft_split.c \
$(STRING_DIR)/ft_strchr.c \
$(STRING_DIR)/ft_strchr_pos.c \
$(STRING_DIR)/ft_strdup.c \
$(STRING_DIR)/ft_striteri.c \
$(STRING_DIR)/ft_strjoin.c \
$(STRING_DIR)/ft_strlcat.c \
$(STRING_DIR)/ft_strlcpy.c \
$(STRING_DIR)/ft_strlen.c \
$(STRING_DIR)/ft_strmapi.c \
$(STRING_DIR)/ft_strncmp.c \
$(STRING_DIR)/ft_strnstr.c \
$(STRING_DIR)/ft_strrev.c \
$(STRING_DIR)/ft_strrchr.c \
$(STRING_DIR)/ft_strtrim.c \
$(STRING_DIR)/ft_substr.c \
$(STRING_DIR)/ft_subarr_str.c \
$(STRING_DIR)/ft_vstrjoin.c \
$(STRING_DIR)/ft_strnstr_2d.c \
$(STRING_DIR)/ft_strarr_len.c \
$(STRING_DIR)/ft_strarr_strlen.c \
$(STRING_DIR)/ft_flatten.c\
$(STRING_DIR)/ft_strarrdup.c \

# CC=gcc
# CFLAGS=-Wall -Wextra -Werror -ggdb3
CC=cc
CFLAGS=-Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR)

all: $(NAME)

bonus: all

OBJECTS = $(SOURCES:.c=.o)

$(NAME) : $(OBJECTS)
	ar crs $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
