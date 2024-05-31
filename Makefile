NAME		=	push_swap

BONUS_NAME	=	checker

SRC			=	push_swap.c val_and_parse.c list_utils.c op_one.c op_two.c\
				op_three.c order_functions.c order_two.c order_three.c\
				format_check.c ft_free_arg.c\
				lis_algo.c sorter.c ft_display_error.c ft_lst_mod.c\

BONUS_SRC	=	checker.c  check_write.c val_and_parse.c list_utils.c op_one.c\
				check_one.c check_two.c check_three.c ft_free_arg.c\
				ft_display_error.c ft_lst_mod.c format_check.c\
				
LIBFT		=	libft/libft.a

OBJ			=	$(SRC:.c=.o)
BONUS_OBJ	=	$(BONUS_SRC:.c=.o) 

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			@make -s -C ./libft
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
			@echo "PUSH SWAP Compilation: SUCCESS"

bonus:		$(BONUS_OBJ)
			@make -s -C ./libft
			@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ) $(LIBFT)
			@echo "PUSH SWAP BONUS Compilation: SUCCESS"

all:		$(NAME) bonus

clean:
			@make -s clean -C libft
			@${RM} $(OBJ) ${BONUS_OBJ}
			@echo "CLEANING SUCCESS"

fclean: 	clean
			@make -s fclean -C libft
			@${RM} $(NAME) ${BONUS_NAME} ${OBJ} ${BONUS_OBJ}
			@echo "FCLEANING SUCCESS"

re:			fclean bonus

.PHONY:		all clean fclean re
