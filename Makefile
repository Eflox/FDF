
NAME = fdf
LIBFT = ./libft
MLX = ./minilibx_macos
FLAG = -Wall -Wextra -Werror -framework OpenGL -framework AppKit
SRC = src/fdf.c src/bresenham.c src/bonus.c src/keys.c src/mouse.c src/menu.c src/menu2.c src/read_map.c src/draw_map.c src/img_bresenham.c
OBJ = *.o

all: $(NAME)

$(NAME):
	make re -C ./minilibx_macos
	make re -C $(LIBFT)
	gcc $(FLAG) -o $(NAME) -L $(LIBFT) -lft -g -L $(MLX) -lmlx -framework OpenGl -framework AppKit $(SRC)
	
clean:
	/bin/rm -f $(OBJ)
	make clean -C $(LIBFT)
	make clean -C $(MLX)

fclean:
	/bin/rm -f $(NAME)

re: fclean all
