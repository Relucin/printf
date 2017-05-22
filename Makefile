INCLUDES += ft_printf.o ftpf_checks.o ftpf_helpers.o
INCLUDES += ftpf_strings.o ftpf_numbers.o ftpf_otypes.o
INCLUDES += ftpf_parse.o
INCLUDES += ft_isdigit.o ft_memcpy.o ft_strcatmulti.o
INCLUDES += ft_strcpy.o ft_strlcat.o ft_strlen.o
INCLUDES += ft_strncpy.o ft_strnew.o ft_strsub.o
INCLUDES += ft_strupper.o ft_strcat.o

FLAGS2	 = -Wall -Wextra -Werror -g
NAME	 = libftprintf.a

$(NAME): $(INCLUDES)
	ar rc $@ $^

main: $(NAME) main.o ft_putchar.o ft_putendl.o ft_putnbr.o ft_strcmp.o ft_putstr.o
	gcc $(FLAGS2) $(FLAGS) $^ -o $@

%.o: %.c
	gcc $(FLAGS2) -c $^ -o $@

clean:
	rm -rf $(INCLUDES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

all: $(NAME)
