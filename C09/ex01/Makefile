CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCDIR = srcs
HEAD = includes
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
LIBNAME = libft.a


all: $(LIBNAME)
	
$(LIBNAME): $(OBJS)
	ar rc $(LIBNAME) $(OBJS)
	ranlib $(LIBNAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf libft.a

re: fclean all

