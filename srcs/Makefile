NAME = libft.a
#Compilador y flags

CC = gcc
CFLAGS = -Wall -Wextra -Werror
#Archivos
SRC =	create_input.c

# Carpeta libft
LIBFT_DIR = libft/libft.a

# Carpeta gnl
GNL_DIR = gnl

#Carperta printf
PRINTF_DIR = libftprintf

# Reglas
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

#Salida .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Limpia libreria y .o
clean:
	rm -f $(OBJ) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(PRINTF_DIR) clean


fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	make -C $(PRINTF_DIR) fclean


#Reconstruye
re: fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus


BONUS = 

OBJ = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

# Reglas
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

#Salida .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Limpia libreria y .o
clean:
	rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) 

#Reconstruye
re: fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
