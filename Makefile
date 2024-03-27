NAME		=	push_swap

SRC			=	lis_algo.c list_utils.c op_one.c\
				op_three.c op_two order_functions.c order_three.c\
				order_two.c push_swap.c sorter.c\

LIBFT		=	libft/libft.a

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -C ./libft/
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C ./libft
			${RM} $(OBJ) $(OBJ_BONUS)

fclean: 	clean
			make fclean -C ./libft
			${RM} $(NAME) $(NAME_BONUS) ${OBJ} $(OBJ_BONUS)

re:			fclean

make:		all 
			$(CC) $(CFLAGS) -o $(LIBFT)


.PHONY:		all clean fclean re