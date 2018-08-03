
# include "fractol.h"

void		init_july(t_img *img, double h)
{
	img->zone.x1 = -2.5 + h;
	img->zone.x2 = 2.5 - h;
	img->zone.y1 = -2 + h;
	img->zone.y2 = 2 - h;
	img->iteration = 25;
	img->zoom_x = WIN_X / (img->zone.x2 - img->zone.x1);
	img->zoom_y = WIN_Y / (img->zone.y2 - img->zone.y1);
}

void		loop_july(t_img *img, t_set set)
{
	double		p_real;
	double		p_imag;
	double		z_real;
	double		z_imag;
	double		tmp;
	int		i;
	int		x;
	int		y;

	x = 0;
	while (x < WIN_X)
	{
		y = 0;
		while (y < WIN_Y)
		{
			p_real = img->j_r;
			p_imag = img->j_i;
			z_real = x / img->zoom_x + img->zone.x1;
			z_imag = y / img->zoom_y + img->zone.y1;
			i = 0;
			while ((z_real * z_real + z_imag * z_imag) < 4 && i < img->iteration)
			{
				tmp = z_real;
				z_real = z_real * z_real - z_imag * z_imag + p_real;
				z_imag = 2 * z_imag * tmp + p_imag;
				i++;
			}
			if (i == img->iteration)
				ft_change_color(img, x, y, (t_color){0,0,0});
			else
				ft_change_color(img, x, y, modulate_color(i, choose_color(set, i)));
			y++;
		}
		x++;
	}
}