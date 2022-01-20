NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I. -Ilibft/. -c

RM = rm -f
LB_NAME =   libft.a
LIB_DIR =   ./libft

SRCS = ft_printf.c\
	ft_utils.c\
	ft_utils_print.c\
	print_char.c\
	print_decemal.c\
	print_exalower.c\
	print_exaupper.c\
	print_pointer.c\
	print_unsigned.c\
	print_string.c\
	print_percent.c\

OBJS = $(SRCS:.c=.o)

all: ${NAME}
${LIB_DIR}/${LB_NAME}:
		${MAKE} -C $(LIB_DIR)
$(NAME): $(OBJS) ${LIB_DIR}/${LB_NAME}
	cp $(LIB_DIR)/$(LB_NAME) ./$(NAME)
	ar rc $@ $(OBJS)
	/bin/rm -f $(LB_NAME)
	ranlib $(NAME)
	
$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS) $(B_OBJS)
	${MAKE} -C $(LIB_DIR) fclean
fclean: clean
	rm -f $(NAME)
	${MAKE} -C $(LIB_DIR) fclean
re: fclean all
.PHONY: clean fclean all re
