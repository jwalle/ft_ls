NAME = ft_ls

SRC = check.c \
	  file.c \
	  free_all.c \
	  ft_ls.c \
	  ls_l.c \
	  misc.c \
	  output.c \
	  print_r.c \
	  sort.c \
	  sort_st.c \
	  stock.c \
	  ls_dev.c


OBJ = $(SRC:.c=.o)

all : $(NAME)


$(NAME) :
	gcc -c -g -Wall -Werror -Wextra -I libft/includes/ $(SRC)
	gcc -o $(NAME) -g $(OBJ) -L libft/ -lft
	/bin/rm -f $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)

re: fclean all
