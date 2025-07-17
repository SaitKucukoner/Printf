NAME = libftprintf.a

SRCS =	ft_printf.c\
				ft_printf_utils.c

OBJS = $(SRCS.c = .o)

OBJS    = $(SRCS:.c=.o)

LIBC    = ar rcs
CC      = cc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) 
	$(LIBC) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re