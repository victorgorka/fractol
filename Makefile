# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 16:49:46 by vde-prad          #+#    #+#              #
#    Updated: 2023/04/04 14:21:41 by vde-prad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	main.c \
			mandelbrot.c \
			julia.c \
			utils.c \
			burningship.c \
			hooks.c

OBJS	= ${SRCS:.c=.o}
NAME	= fractol
LIBFT	= libft/libft.a
MLX_L	= -L MLX42 -l mlx42
GLFW_L	= -L /sgoinfre/goinfre/Perso/vde-prad/homebrew/Cellar/glfw/3.3.7/lib/ -l glfw
INCLUD	= -I MLX42/include
CFLAGS	= -Wall -Werror -Wextra

all: libft mlx_lib ${NAME}

libft:
	@echo "COMPILING LIBFT"
	@${MAKE} -C ./libft

mlx_lib:
	@echo "COMPILANDO MLX42\n"
	@${MAKE} -C ./MLX42

${NAME}: ${OBJS}
	@echo "COMPILANDO fractol\n"
	@gcc ${CFLAGS} ${OBJS} ${LIBFT} ${MLX_L} ${GLFW_L} ${INCLUD} -o ${NAME}

re: fclean all

clean:
	@echo "CLEAN\n"
	@${MAKE} -C ./MLX42 clean
	@rm -f ${OBJS}

fclean: clean
	@${MAKE} -C ./MLX42 fclean
	@rm -f ${NAME}

.PHONY: all re clean fclean mlx_lib libft
