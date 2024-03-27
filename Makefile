NAME		=	push_swap

SRC			=	push_swap.c lis_algo.c list_utils.c op_one.c\
				op_three.c op_two order_functions.c order_three.c\
				display_error.c order_two.c  sorter.c\

LIBFT		=	libft/libft.a

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -C ./libft/
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C ./libft
			rm -f $(OBJ) 

fclean: 	clean
			make fclean -C ./libft
			rm -f $(NAME) ${OBJ}

re:			fclean

make:		all 
			$(CC) $(CFLAGS) -o $(LIBFT)


.PHONY:		all clean fclean re