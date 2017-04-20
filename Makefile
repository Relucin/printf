INCLUDES = ft_printf.o \
			ftpf_checks.o \
			ftpf_helpers.o \
			ftpf_strings.o \
			ftpf_numbers.o \
			ftpf_otypes.o \
			ftpf_parse.o

FLAGS 	 = -Llibft -lft -L. -lftprintf
FLAGS2	 = -Ilibft -I. -Wall -Wextra -Werror -g
NAME	 = libftprintf.a

$(NAME): $(INCLUDES)
	make -C libft
	ar rc $@ libft/*.o $^

main: $(NAME) main.o
	make -C libft
	gcc $(FLAGS2) $(FLAGS) main.o -o $@

%.o: %.c
	gcc $(FLAGS2) -c $^ -o $@

clean:
	rm -rf $(INCLUDES)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all

all: $(NAME)
