NAME		=	push_swap 

SRC			=	push_swap.c list_utils.c op_one.c op_two.c\
				op_three.c order_functions.c order_two.c order_three.c\
				format_check.c\
				lis_algo.c sorter.c ft_display_error.c ft_lst_mod.c\

BONUS_SRC	=	checker.c  check_write.c\
				check_one.c check_two.c check_three\

LIBFT		=	libft/libft.a

OBJ			=	$(SRC:.c=.o)
BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

bonus:		$(BONUS_OBJ)
            make -C ./libft
            $(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJ) $(LIBFT)

all:		$(NAME) bonus

clean:
			make clean -C libft
			${RM} $(OBJ) ${BONUS_OBJ}

fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) ${OBJ} ${BONUS_OBJ}

re:			fclean bonus

.PHONY:		all clean fclean re
