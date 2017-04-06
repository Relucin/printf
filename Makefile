INCLUDES = ft_printf.o \
						ftpf_checks.o \
						ftpf_makeparts.o \
						ftpf_strings.o \
						ft_darray.o \
						main.o
FLAGS 	 = -Llibft -lft
FLAGS2	 = -Ilibft -I. -Wall -Wextra -Werror
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
