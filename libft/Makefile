#OUTPUT
NAME = libft.a

#DIR

HDIR = .

#FILE
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
			ft_memccpy.c\
			ft_memcpy.c\
			ft_strchr.c\
			ft_strlen.c\
			ft_strrchr.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_calloc.c\
			ft_split.c\
			ft_itoa.c\
			ft_putnbr_fd.c\
			ft_strmapi.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\

OBJ = $(addsuffix .o, $(basename $(SRCS))

HEADER = $(addprefix $(HDIR)/, $(addsuffix .h, $(basename $(NAME))))

BONUS = ft_lstadd_back.c\
			ft_lstmap.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstnew.c\
			ft_lstsize.c\

FLAGS = -Wall  -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(SRCS:%.c=%.o) $(SRCS) $(HEADER)
		gcc $(FLAGS) -c $(SRCS) -I .
		ar rc $(NAME) $(SRCS:.c=.o) $^
		ranlib $(NAME)

bonus:
		gcc $(FLAGS) -c $(SRCS) $(BONUS) -I .
		ar rc $(NAME) $(BONUS:.c=.o) $(SRCS:.c=.o) $^
		ranlib $(NAME)

%.o : %.c
			gcc ${FLAGS} -I . -c $< -o $@

clean:
		rm -rf $(SRCS:.c=.o)

clean_b:
		rm -rf $(BONUS:.c=.o)

fclean: clean clean_b
		rm -rf $(NAME)

re: fclean all

.PHONY		:	all clean fclean re bonus clean_b