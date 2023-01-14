NAME = pipex

SRCS =	pipex.c             \
		parsing.c           \
		exec.c              \
		parsing2.c          \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS =  -g -Wall -Wextra -Werror 

all:$(NAME)

$(NAME):$(OBJS) 
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a -o $(NAME)
clean:
	rm -f $(OBJS)
	rm -f ./libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all