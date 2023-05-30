NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wextra -Werror -Wall -I./lib/libft/includes -I./includes/ -g
LIB_PATH	=	lib/
LIBFT_PATH	=	$(LIB_PATH)libft
LIBFT_NAME	=	libft.a
SRC			=	main.c
SRC_MAP		=	map/check_map.c			\
				map/check_file.c
SRC_ENGINE	=	engine/vector.c
TEST_NAME	=	test_$(NAME)
SRC_TEST	=	test/main.c				\
				test/map.c				\
				test/test.c

all: $(LIBFT_NAME) $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(SRC_MAP) $(SRC_ENGINE) -o $(NAME) $(LIBFT_PATH)/$(LIBFT_NAME)
	
$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

$(MLX_NAME):
	make -C $(MLX_PATH)

test_$(NAME): $(LIBFT_NAME)
	@clear
	@echo -e '\x1b[93mCompiling start...\x1b[0m'
	$(CC) $(CFLAGS) $(SRC_MAP) $(SRC_ENGINE) $(SRC_TEST) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(TEST_NAME) 
	@echo -e '\x1b[93mCompiling end\x1b[0m'
	./$(TEST_NAME)
	@line=$$(valgrind ./$(TEST_NAME) 2>&1 | grep -oP 'total heap usage: \d+ allocs, \d+ frees'); \
    allocs=$$(echo "$$line" | grep -oP 'total heap usage: \K\d+'); \
    frees=$$(echo "$$line" | grep -oP 'total heap usage: \d+ allocs, \K\d+'); \
    if [ "$$allocs" -gt "$$frees" ]; then \
	echo "\033[91m[ KO ] : valgrind, more allocs\033[0m"; \
    elif [ "$$allocs" -lt "$$frees" ]; then \
	echo "\033[91m[ KO ] : valgrind, more frees\033[0m"; \
    else \
	echo "\033[92m[ OK ]\033[0m : valgrind"; \
    fi
	@rm -f $(TEST_NAME)

valgrind_test_$(NAME): $(LIBFT_NAME)
	@clear
	@echo -e '\x1b[93mCompiling start...\x1b[0m'
	$(CC) $(CFLAGS) $(SRC_MAP) $(SRC_ENGINE) $(SRC_TEST) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(TEST_NAME) 
	@echo -e '\x1b[93mCompiling end\x1b[0m'
	@valgrind ./$(TEST_NAME)
	@rm -f $(TEST_NAME)

clean:
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)
