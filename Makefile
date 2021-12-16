SRCS		=	ft_printf.c \
				ft_printf2.c \
				ft_utils.c \

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -I ./

NAME		=	libftprintf.a

.c.o:			$(SRCS)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				ar rcs $@ $^

all:			$(NAME)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re