
#include "fractol.h"

int		display_erro(void)
{
	ft_putendl_fd("usage : ./fractol + [fractal]", 2);
	ft_putendl_fd(" - Mandelbrot", 2);
	ft_putendl_fd(" - Julia", 2);
	return (0);
}

void			selector(int fractal, t_img *img, t_set set)
{
	if (fractal == MANDELBROT)
	{
		init_man(img, img->zoom);
		loop_man(img, set);
	}
	else if (fractal == JULIA)
	{
		init_july(img, img->zoom);
		loop_july(img, set);
	}
	else if (fractal == THIRD)
	{
		init_third(img);
		loop_third(img, set);
	}
}

void            go(int fractal)
{
	void    *mlx_ptr;
	void    *win_ptr;
	void    *img_ptr;
	t_img   img;
	t_set	set;

	mlx_ptr = mlx_init();
	img.mlx_ptr = mlx_ptr;
	win_ptr = mlx_new_window(mlx_ptr,WIN_X, WIN_Y, "ntm");
	img.win_ptr = win_ptr;
	img_ptr = mlx_new_image(mlx_ptr, WIN_X, WIN_Y);
	img.img_ptr = img_ptr;
	img.j_r = -0.8;
	img.j_i = -0.15;
	img.zoom = 0;
	img.fractal = fractal;
	img.iteration = 25;
	img.zone_mem = (unsigned char *)mlx_get_data_addr(img_ptr, &img.bit_p, &img.size_line, &img.endian);
	set = init_color(0);
	selector(fractal, &img, set);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_hook(win_ptr, 6, 1L << 8, &ft_mouse, &img);
	mlx_hook(win_ptr, 4, 1 << 11, &ft_mouse_wheel, &img);
	mlx_key_hook(win_ptr, esc_hook, &img);
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
		else if (ft_strcmp(argv[1], "Third") == 0)
			go(THIRD);
		else
			return (display_erro());
	}
	else
		display_erro();
	return (0);
}



/*



mlx_hook(param->win->win_ptr, 6, 1L << 8, &ft_mouse, (void*)param);
mlx_hook(param->win->win_ptr, 4, 1 << 11, &ft_mouse_wheel, (void*)param); (modifié)
int    ft_mouse(int x, int y, void *param) (modifié)
int    ft_mouse_wheel(int key, int x, int y, void *param) (modifié)


*/