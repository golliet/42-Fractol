
# include "fractol.h"

int esc_hook(int keycode, void *param)
{
	t_img *img;

	img = (t_img*)param;
	if (keycode == KEY_ESC)
	{
		(void)param;
		exit(0);
	}
	if (keycode == KEY_DOWN)
	{
		if (img->iteration > 250)
			return (0);
		img->iteration += 10;
		mlx_destroy_image(img->mlx_ptr, img->img_ptr);
		img->img_ptr = mlx_new_image(img->mlx_ptr, WIN_X, WIN_Y);
		img->zone_mem = (unsigned char *)mlx_get_data_addr(img->img_ptr, &img->bit_p, &img->size_line, &img->endian);
		selector(img->fractal, img, init_color(0));
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (keycode == KEY_UP)
	{
		if (img->iteration < 10)
			return (0);
		img->iteration -= 10;
		mlx_destroy_image(img->mlx_ptr, img->img_ptr);
		img->img_ptr = mlx_new_image(img->mlx_ptr, WIN_X, WIN_Y);
		img->zone_mem = (unsigned char *)mlx_get_data_addr(img->img_ptr, &img->bit_p, &img->size_line, &img->endian);
		selector(img->fractal, img, init_color(0));
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
    return (1);
}

double				ft_calc_x(int x)
{
	double scale;
	double nb_pos;
	double pos;

	scale = 2 / PAS;
	nb_pos = WIN_X / scale;
	if (x >= WIN_X/2)
		pos = (x / nb_pos) * PAS - 1;
	if (x < WIN_X/2)
		pos = -((WIN_X/2 - x) / nb_pos) * PAS;
	return (pos);
}

double				ft_calc_y(int y)
{
	double scale;
	double nb_pos;
	double pos;

	scale = 1 / PAS2;
	nb_pos = WIN_Y / scale;
	pos = (y / nb_pos) * PAS2 - 1;
	return (pos);
}

int    				ft_mouse(int x, int y, void *param)
{
	t_img *img;

	if (x < 0 || y < 0 || x > WIN_X || y > WIN_Y)
		return (0);
	img = (t_img*)param;
	if (img->fractal == JULIA)
	{
		mlx_destroy_image(img->mlx_ptr, img->img_ptr);
		img->img_ptr = mlx_new_image(img->mlx_ptr, WIN_X, WIN_Y);
		img->zone_mem = (unsigned char *)mlx_get_data_addr(img->img_ptr, &img->bit_p, &img->size_line, &img->endian);
		img->j_r = ft_calc_x(x);
		img->j_i = ft_calc_y(y);
		selector(img->fractal, img, init_color(0));
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	return (1);
}
