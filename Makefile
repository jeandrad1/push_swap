NAME		=	push_swap

SRC			=	push_swap.c list_utils.c op_one.c op_two.c\
				op_three.c order_functions.c order_two.c order_three.c\
				format_check.c\
				lis_algo.c sorter.c ft_display_error.c ft_lst_mod.c\

LIBFT		=	libft/libft.a

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C libft
			${RM} $(OBJ) 

fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) ${OBJ}

re:			fclean bonus

bonus:		all $(OBJ_BONUS)
			$(CC) $(CFLAGS) -o $(LIBFT)

.PHONY:		all clean fclean re
