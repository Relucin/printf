INCLUDES = ft_printf.o \
						ftpf_checks.o
<<<<<<< HEAD
FLAGS 	 =  -Llibft -lft
=======
FLAGS 	 =  -L../libft -lft
>>>>>>> 13c4a04b057e381adbd4cb87ade59ea59b313529
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
