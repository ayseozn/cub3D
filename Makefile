NAME = cub3D
CC   = cc -Wall -Wextra -Werror
LFLAGS = -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit
SOURCES = src/main.c \
          src/exit.c \
		  src/hook.c \
          src/map.c \
          src/map_control.c \
          src/initialize.c \
		  src/utils.c \
		  src/ray.c \
		  src/game.c \
		  src/raycast.c \

OBJ = $(SOURCES:.c=.o)

all     :   $(NAME)

$(NAME) :  $(OBJ)
	@make -C libft &> /dev/null
	@make -C mlx &> /dev/null
	$(CC) $(OBJ) -o $(NAME) $(LFLAGS)
	@echo "✅"

clean   :
	@make -C libft clean
	@make -C mlx clean
	@rm -f $(OBJ)
	@echo "🗑️"

fclean  :
	@make -C libft fclean
	@make -s -C mlx clean
	@rm -f $(NAME) $(OBJ)

re      :   fclean all

.PHONY  :   all clean fclean re
