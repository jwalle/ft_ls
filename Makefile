all : 
	gcc -c -g -Wall -Werror -Wextra -I libft/includes/ *.c
	gcc -o ft_ls -g *.o -L libft/ -lft
	rm -rf *.o

