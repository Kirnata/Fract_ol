NAME = fractol

MLX			= libmlx.dylib

MLX_H		= ./mlx/mlx.h

SRCS		= sources/main.c \
			sources/draw.c \
			sources/init.c \
			sources/ft_mandelbrot.c \
			sources/ft_julia.c \
			sources/ft_ship.c \
			sources/do_fractal.c \
			sources/color.c \
			sources/hooks.c \
			sources/utils.c \
			sources/ft_atod.c \

OBJS		= $(SRCS:.c=.o)

OBJ_D		= $(SRCS:.c=.d)

CC			= cc

FLAGS		= -pthread -Wall -Wextra -Werror -O3 -MMD

LIBC		= ar rc

LIBR		= ranlib

LIBFT		= libft/libft.a

RM			= rm -f

RED			= \x1b[31m
RESET		= \x1b[0m
BLUE		= \x1b[34m
GREEN		= \x1b[32m

$(NAME):	$(OBJS) $(MLX)
			@make bonus -C libft
			@echo "$(RED)Generating object files $(RESET)"
			@echo "$(BLUE)Compiling and linking binary file $(RESET)"
			$(CC) $(FLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			@echo "$(GREEN)IT IS FINALLY GENERATED (to use it run $(RED)./$(NAME)$(GREEN)) $(RESET)"

%.o: %.c
	$(CC) $(FLAGS) -I includes -I libft -I mlx -c $< -o $(<:.c=.o)

$(MLX):		$(MLX_H)
			./build_mlx.sh

all:		$(NAME)

clean:
			@$(RM) $(OBJ_D) $(OBJS)
			make clean -C libft


fclean: clean
			@$(RM) $(NAME)
			make fclean -C libft

re: 		fclean all

.PHONY: 	all clean fclean re bonus

-include $(OBJ_D)