NAME = fillit
FLAGS = -Wall -Wextra -Werror
FILES = ./fillit.c \
	./solve.c \
	./valid_forms.c \
	./translator.c \

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o fillit $(FILES) libft/libft.a

clean:
	/bin/rm -f fillit

fclean : clean

re: fclean all
