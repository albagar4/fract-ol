NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF_DIR = include/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_DIR = $(FT_PRINTF_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = include/minilibx
MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a
MLXFLAG = -L $(MINILIBX_DIR) -lmlx -lXext -lX11
INCLUDES = -I . -I include -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I $(MINILIBX_DIR)

FRACTOL_SRCS = src/main.c
FRACTOL_OBJS = $(FRACTOL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(FRACTOL_OBJS) $(LIBFT) $(FT_PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) $(INCLUDES) $(FRACTOL_OBJS) $(LIBFT) $(FT_PRINTF) $(MLXFLAG) -o fractol

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(FRACTOL_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

