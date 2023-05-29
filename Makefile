NAME		=	so_long
CC			=	clang
CFLAGS		=	-Wextra -Werror -Wall
LIB_PATH	=	lib/
LIBFT_PATH	=	$(LIB_PATH)libft
LIBFT_NAME	=	libft.a
SRC			=	main.c

all: $(LIBFT_NAME) $(NAME) #$(MLX_NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME) 
	
$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

$(MLX_NAME):
	make -C $(MLX_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	#make clean -C $(MLX_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)
