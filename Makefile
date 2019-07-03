NAME = fillit
FLAGS = -Wall -Wextra -Werror
FILES = ./fillit.c \
	./solve2.c \
	./translator.c \
	./validation.c \

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o fillit $(FILES) libft/libft.a

clean:
	/bin/rm -f fillit

fclean : clean

re: fclean all
