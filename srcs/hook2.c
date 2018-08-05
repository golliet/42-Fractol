
# include "fractol.h"

double			ft_control_zoom(t_img *img)
{
	return (1 - img->zoom/5);
}

int				ft_mouse_wheel(int key, int x, int y, void *param)
{
	t_img *img;
	(void)x;
	(void)y;

	img = (t_img*)param;
	if (key == 5 && img->zoom < 5)
		img->zoom += ft_control_zoom(img);
	else if (key == 4)
		img->zoom -= 0.20;
	else
		return (0);
	if (img->iteration < 15)
		img->iteration = 15;
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	img->img_ptr = mlx_new_image(img->mlx_ptr, WIN_X, WIN_Y);
	img->zone_mem = (unsigned char *)mlx_get_data_addr(img->img_ptr, &img->bit_p, &img->size_line, &img->endian);
	selector(img->fractal, img, init_color(0));
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	return (0);
}
