INCLUDES = ft_printf.o \
						ftpf_checks.o
FLAGS 	 =  -L../libft -lft
NAME		 = main

all: $(NAME)

$(NAME): $(INCLUDES)
	gcc $(FLAGS) $(INCLUDES) -o $@

%.o: %.c
	gcc -c $^ -o $@

clean:
	rm -rf $(INCLUDES)

fclean: clean
	rm -rf $(NAME)
