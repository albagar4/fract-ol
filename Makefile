NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF_DIR = include/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_DIR = $(FT_PRINTF_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_LINUX_PATH = include/minilibx_linux
MINILIBX_MAC_PATH = include/minilibx_mac
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
MLXFLAG = -L $(MINILIBX_LINUX_PATH) -lmlx -lXext -lX11 -lm
MLX_PATH = $(MINILIBX_LINUX_PATH)
endif
ifeq ($(UNAME_S), Darwin)
MLXFLAG = -L $(MINILIBX_MAC_PATH) -lmlx -framework OpenGL -framework AppKit
MLX_PATH = $(MINILIBX_MAC_PATH)
endif
INCLUDES = -I . -I include -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I $(MLX_PATH)

FRACTOL_SRCS = src/main.c src/mandelbrot.c src/utils.c src/hook_events.c src/preset_fractol.c
FRACTOL_OBJS = $(FRACTOL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(FRACTOL_OBJS) $(LIBFT) $(FT_PRINTF) $(UNAME_S)
	 $(CC) $(CFLAGS) $(INCLUDES) $(FRACTOL_OBJS) $(LIBFT) $(FT_PRINTF) $(MLXFLAG) -o fractol

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(UNAME_S):
	@$(MAKE) -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(FRACTOL_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

