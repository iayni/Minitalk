NAME = minifunc.a

CFLAGS = -Wall -Wextra -Werror -c

RM = rm -f

SRCS = server.c client.c ft_putstr.c ft_putnbr.c ft_atoi.c ft_strlen.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) ft_minitalk.h
	gcc $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

