
#include "fractol.h"

int		display_erro(void)
{
	ft_putendl_fd("usage : ./fractol + [fractal]", 2);
	ft_putendl_fd(" - Mandelbrot", 2);
	ft_putendl_fd(" - Julia", 2);
	return (0);
}

void            ft_change_color(t_img *img, int x, int y, t_color color)
{
        int nb;

        if (x < 0 || y < 0)
                return ;
        if (x >= WIN_X || y >= WIN_Y)
                return ;
        nb = y * img->size_line + (img->bit_p/8) * x;
        img->zone_mem[nb] = color.red;
        img->zone_mem[nb + 1] = color.green;
        img->zone_mem[nb + 2] = color.blue;
}

int esc_hook(int keycode, void *param)
{
        if (keycode == ESC)
        {
                (void)param;
                exit(0);
        }
        return (1);
}

void			selector(int fractal, t_img *img)
{
	if (fractal == MANDELBROT)
	{
		init_man(img);
		loop_man(img);
	}
	else if (fractal == JULIA)
	{
		init_july(img);
		loop_july(img);
	}
}

void            go(int fractal)
{
	void    *mlx_ptr;
	void    *win_ptr;
	void    *img_ptr;
	t_img   img;

	(void)fractal;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr,WIN_X, WIN_Y, "ntm");
	img_ptr = mlx_new_image(mlx_ptr, WIN_X, WIN_Y);
	img.zone_mem = (unsigned char *)mlx_get_data_addr(img_ptr, &img.bit_p, &img.size_line, &img.endian);

	selector(fractal, &img);

	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_key_hook(win_ptr, esc_hook, NULL);
	mlx_loop(mlx_ptr);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
			go(MANDELBROT);
		else if (ft_strcmp(argv[1], "Julia") == 0)
			go(JULIA);
		else
			return (display_erro());
	}
	else
		display_erro();
	return (0);
}