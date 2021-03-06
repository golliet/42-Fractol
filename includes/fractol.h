/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 07:59:35 by golliet           #+#    #+#             */
/*   Updated: 2018/08/07 16:57:11 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define BROT 1
# define JULIA 2
# define THIRD 3

# define WIN_X 1200
# define WIN_Y 900
# define PAS 0.01
# define PAS2 0.005

# define KEY_ESC 53
# define PAD_MINUS 78
# define PAD_PLUS 69
# define RIGHT_CLICK 1
# define LEFT_CLICK 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_ENTER 36
# define KEY_MINUS 27
# define KEY_PLUS 24
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_LEFT 124
# define KEY_DOWN 126
# define KEY_RIGHT 123
# define KEY_UP 125
# define KEY_SPACE 49
# define KEY_A 0

typedef struct			s_zone
{
	double				x1;
	double				x2;
	double				y1;
	double				y2;
}						t_zone;

typedef struct			s_img
{
	unsigned char		*zone_mem;
	int					bit_p;
	int					endian;
	int					size_line;
	t_zone				zone;
	int					iteration;
	double				zoom_x;
	double				zoom_y;
	int					fractal;
	double				j_r;
	double				j_i;
	void				*win_ptr;
	void				*mlx_ptr;
	void				*img_ptr;
	double				zoom;
	int					color;
}						t_img;

typedef struct			s_color
{
	int					red;
	int					green;
	int					blue;
}						t_color;

typedef struct			s_set
{
	t_color				c0;
	t_color				c1;
	t_color				c2;
	t_color				c3;
	t_color				c4;
	t_color				c5;
}						t_set;

typedef struct			s_var
{
	double				p_real;
	double				p_i;
	double				z_real;
	double				z_imag;
	double				tmp;
	int					i;
	int					x;
	int					y;
}						t_var;

/*
** Mandelbrot
*/

void					init_man(t_img *img, double h);
void					loop_man(t_img *img, t_set set, t_var *var);

/*
** july
*/

void					init_july(t_img *img, double h);
void					loop_july(t_img *img, t_set set, t_var *var);

/*
** third
*/

void					init_third(t_img *img, double h);
void					loop_third(t_img *img, t_set set, t_var *var);

/*
** Draw
*/

void					ft_change_color(t_img *img, int x, int y, t_color c);

/*
** Color
*/

t_set					init_color(int i);
t_color					choose_color(t_set col, int i);
t_color					modulate_color(int n, t_color color);

/*
** HOOK
*/

int						esc_hook(int keycode, void *param);
int						ft_mouse_wheel(int key, int x, int y, void *param);
int						ft_mouse(int x, int y, void *param);

/*
** MISC
*/

void					selector(int fractal, t_img *img, t_set set);

#endif
