NAME = libft.a
FLAG = -Wall -Wextra -Werror

SRC = 	ft_isalpha.c	\
	ft_isdigit.c 		\
	ft_isalnum.c 		\
	ft_isascii.c 		\
	ft_isprint.c 		\
	ft_strlen.c 		\
	ft_memset.c 		\
	ft_bzero.c			\
	ft_memcpy.c 		\
	ft_memmove.c 		\
	ft_strlcpy.c 		\
	ft_strcpy.c			\
	ft_strlcat.c 		\
	ft_toupper.c 		\
	ft_tolower.c 		\
	ft_strchr.c 		\
	ft_strrchr.c 		\
	ft_strcmp.c 		\
	ft_strncmp.c 		\
	ft_memchr.c 		\
	ft_memcmp.c 		\
	ft_strnstr.c 		\
	ft_atoi.c 			\
	ft_calloc.c 		\
	ft_strdup.c 		\
	ft_strdup2.c 		\
	ft_substr.c 		\
	ft_strjoin.c 		\
	ft_strtrim.c 		\
	ft_split.c 			\
	ft_itoa.c 			\
	ft_strmapi.c 		\
	ft_striteri.c 		\
	ft_putchar_fd.c 	\
	ft_putstr_fd.c 		\
	ft_putendl_fd.c 	\
	ft_putnbr_fd.c		\
	ft_free_stash.c		\
	get_next_line.c

CC	= gcc

all: $(NAME)

$(NAME):
	@$(CC) $(FLAG) -c $(SRC)
	@ar rc $(NAME) *.o

clean:
	@/bin/rm -f *.o *.out

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "🗑️"

re: fclean all

.PHONY: all clean fclean re
