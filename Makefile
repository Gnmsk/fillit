NAME = fillit
FLAGS = -Wall -Wextra -Werror -g
FILES = ./fillit.c \
	./solve2.c \
	./translator.c \
	./validation.c \

all: $(NAME)

$(NAME): 
	make -C ./libft
	gcc $(FLAGS) -o fillit $(FILES) libft/libft.a

clean:
	make clean -C ./libft

fclean : clean
	make fclean -C ./libft
	rm -f fillit

re: fclean all
