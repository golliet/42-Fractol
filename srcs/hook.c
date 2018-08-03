
# include "fractol.h"

int esc_hook(int keycode, void *param)
{
        if (keycode == ESC)
        {
            (void)param;
            exit(0);
        }
        return (1);
}

double				ft_calc_x(int x)
{
	// entre -1 et 1
	double scale;
	double nb_pos;
	double pos;

	scale = 2 / PAS;
	nb_pos = WIN_X / 2 / scale;
	if (x >= WIN_X/2)
	{
		if (x >= WIN_X/2 + WIN_X/4)
			pos = (x / nb_pos) * PAS -1;
		if (x < WIN_X/2 + WIN_X/4)
			pos = -((WIN_X/4 - x) / nb_pos) * PAS;
	}
	else
	{
		if (x >= WIN_X/4)
			pos = (x / nb_pos) * PAS -1;
		if (x < WIN_X/4)
			pos = -((WIN_X/4 - x) / nb_pos) * PAS;
	}
	return (pos);
}

double				ft_calc_y(int y)
{
	// entre -1 et 1
	double scale;
	double nb_pos;
	double pos;

	scale = 1 / PAS2;
	nb_pos = WIN_Y / scale;
	if (y >= WIN_Y/2 + WIN_Y/4)
		pos = (y / nb_pos) * PAS -1;
	if (y < WIN_Y/2 + WIN_Y/4)
		pos = -((WIN_Y/4 - y) / nb_pos) * PAS;
	return (pos);
}

int    				ft_mouse(int x, int y, void *param)
{
	t_img *img;

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
