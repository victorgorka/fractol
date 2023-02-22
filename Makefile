SRCS	= main.c

OBJS	= ${SRCS:.c=.o}
NAME	= fractol
MLX_L	= -L MLX42 -l mlx42 
GLFW_L	= -L /sgoinfre/goinfre/Perso/vde-prad/homebrew/Cellar/glfw/3.3.7/lib/ -l glfw 
INCLUD	= -I MLX42/include
CFLAGS	= -Wall -Werror -Wextra

all: mlx_lib ${NAME}

mlx_lib:
	@echo "COMPILANDO MLX42\n"	
	@${MAKE} -C ./MLX42

${NAME}: ${OBJS}
	@echo "COMPILANDO fractol\n"
	@gcc ${CFLAGS} ${OBJS} ${MLX_L} ${GLFW_L} ${INCLUD} -o ${NAME}

re: fclean all

clean:
	@echo "CLEAN\n"
	@${MAKE} -C ./MLX42 clean
	@rm -f ${OBJS}

fclean: clean
	@${MAKE} -C ./MLX42 fclean
	@rm -f ${NAME}

.PHONY: all re clean fclean mlx_lib