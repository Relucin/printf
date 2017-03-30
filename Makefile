INCLUDES = ft_printf.o \
						ftpf_checks.o
FLAGS 	 = -Llibft -lft
FLAGS2	 = -Ilibft
NAME		 = main

all: $(NAME)

$(NAME): $(INCLUDES)
	make -C libft
	gcc $(FLAGS2) $(FLAGS) $(INCLUDES) -o $@

%.o: %.c
	gcc $(FLAGS2) -c $^ -o $@

clean:
	rm -rf $(INCLUDES)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean
