#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define MANDELBROT 1
# define JULIA 2
# define WIN_X 1000
# define WIN_Y 750
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
}								t_img;

typedef struct					s_color
{
	int							red;
	int							blue;
	int							green;
}								t_color;

/*
** Mandelbrot
*/

void				init_man(t_img *img);
void				loop_man(t_img *img);

/*
** july
*/

void				init_july(t_img *img);
void				loop_july(t_img *img);

/*
** Draw
*/

void				ft_change_color(t_img *img, int x, int y, t_color color);

#endif
