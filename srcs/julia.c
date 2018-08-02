
# include "fractol.h"

void		init_july(t_img *img)
{
	img->zone.x1 = -2.5;
	img->zone.x2 = 1;
	img->zone.y1 = -1;
	img->zone.y2 = 1;
	img->iteration = 50;
	img->zoom_x = WIN_X / (img->zone.x2 - img->zone.x1);
	img->zoom_y = WIN_Y / (img->zone.y2 - img->zone.y1);
}

void		loop_july(t_img *img)
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
			p_real = -0.8;
			p_imag = 0.2;
			z_real = x / img->zoom_x*1.2 + img->zone.x1;
			z_imag = y / img->zoom_y *1.2 + img->zone.y1;
			i = 0;
			while ((z_real * z_real + z_imag * z_imag) < 4 && i < img->iteration)
			{
				tmp = z_real;
				z_real = z_real * z_real - z_imag * z_imag + p_real;
				z_imag = 2 * z_imag * tmp + p_imag;
				i++;
			}
			if (i == img->iteration)
				ft_change_color(img, x, y, (t_color){255,255,255});
			else
				ft_change_color(img, x, y, (t_color){i * 255 / img->iteration ,0, 0});
			y++;
		}
		x++;
	}
}