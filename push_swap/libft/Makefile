NAME = libft.a

#COMPILE

CC = gcc
CFLAGS = -Wall -Wextra -Werror

#LIBFT

LIBFT = libft/libft.a

#DIRECTORY

DIR_BUILD = build/

SRCS = ft_isalnum.c\
		ft_isdigit.c\
		ft_memchr.c\
		ft_memmove.c\
		ft_strlcat.c\
		ft_strncmp.c\
		ft_tolower.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isprint.c\
		ft_memcmp.c\
		ft_memset.c\
		ft_strlcpy.c\
		ft_strnstr.c\
		ft_toupper.c\
		ft_bzero.c\
		ft_isascii.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strlen.c\
		ft_strrchr.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_calloc.c\
		ft_split.c\
		ft_itoa.c\
		ft_putnbr_fd.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_lstadd_back.c\
		ft_lstmap.c\
		ft_lstadd_front.c\
		ft_lstclear.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstlast.c\
		ft_lstnew.c\
		ft_lstsize.c\

OBJS = $(addprefix $(DIR_BUILD), $(SRCS:.c=.o))

all : $(DIR_BUILD) $(NAME)

$(DIR_BUILD):
	mkdir -p $@

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)


$(OBJS): $(DIR_BUILD)%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(DIR_BUILD)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
