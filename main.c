// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "fractol.h"

void	mandelbrot(t_data *data)
{
	int i = 0;
	float c_r = -0.77;
	float c_i = 0.53;
	float tmp_r;
	data->z_r = c_r;
	data->z_i = c_i;
	while (i < 500)
	{
		tmp_r = (data->z_r * data->z_r) - (data->z_i * data->z_i) + c_r;
		data->z_i = 2 * data->z_r * data->z_i + c_i;
		data->z_r = tmp_r;
		printf("iter: %d, coords: %f %fi\n", i, data->z_r, data->z_i);
		if ((data->z_r * data->z_r) + (data->z_i * data->z_i) > 4)
			printf("No pertenece al conjunto\n");
		i++;
	}
}

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_data		data;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		return (EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int));
	mandelbrot(&data);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
