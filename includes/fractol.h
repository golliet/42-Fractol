#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define MANDELBROT 1
# define JULIA 2
# define THIRD 3

# define WIN_X 1400
# define WIN_Y 750
# define PAS 0.01
# define PAS2 0.005

# define ESC 53

typedef struct					s_zone
{
	double						x1;
	double						x2;
	double						y1;
	double						y2;
}								t_zone;

typedef struct					s_img
{
	unsigned char           *zone_mem;
	int						bit_p; // nombre d'octet par pixel
	int						endian; // endian
	int						size_line; // taille en octet d'une ligne en pixel
	t_zone					zone;
	int						iteration;
	double					zoom_x;
	double					zoom_y;
	int						fractal;
	double					j_r;
	double					j_i;
	void					*win_ptr;
	void					*mlx_ptr;
	void					*img_ptr;
}								t_img;

typedef struct					s_color
{
	int							red;
	int							green;
	int							blue;
}								t_color;

typedef struct					s_set
{
	t_color						c0;
	t_color						c1;
	t_color						c2;
	t_color						c3;
	t_color						c4;
	t_color						c5;
}								t_set;

/*
** Mandelbrot
*/

void				init_man(t_img *img, double h);
void				loop_man(t_img *img, t_set set);

/*
** july
*/

void				init_july(t_img *img, double h);
void				loop_july(t_img *img, t_set set);

/*
** third
*/

void				init_third(t_img *img);
void				loop_third(t_img *img, t_set set);

/*
** Draw
*/

void				ft_change_color(t_img *img, int x, int y, t_color color);

/*
** Color
*/

t_set				init_color(int i);
t_color				choose_color(t_set col, int i);
t_color				modulate_color(int n, t_color color);

/*
** HOOK
*/

int 				esc_hook(int keycode, void *param);
int    				ft_mouse(int x, int y, void *param);

/*
** MISC
*/

void				selector(int fractal, t_img *img, t_set set);


#endif
