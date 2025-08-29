NAME = fractol

CC = cc 
CFLAGS = -Wall -Werror -Wextra 
LDFLAGS = -Lminilibx-linux/ -lmlx -lX11 -lXext

SRC = SRC/libft/ft_atoi.c \
	  SRC/libft/ft_strlen.c \
	  SRC/libft/ft_strncmp.c \
	  SRC/libft/ft_putstr_fd.c \
	  SRC/f_envaiermment.c \
	  SRC/f_helmath.c \
	  SRC/f_hrander.c \
	  SRC/f_init.c \
	  SRC/main.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all  clean fclean re
