/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 07:59:35 by golliet           #+#    #+#             */
/*   Updated: 2018/08/07 11:19:13 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_man(t_img *img, double h)
{
	img->zone.x1 = -2.1 + h / 1.2;
	img->zone.x2 = 2.1 - h / 1.2;
	img->zone.y1 = -1.2 + h / 2.1;
	img->zone.y2 = 1.2 - h / 2.1;
	img->iteration = img->iteration;
	img->zoom_x = WIN_X / (img->zone.x2 - img->zone.x1);
	img->zoom_y = WIN_Y / (img->zone.y2 - img->zone.y1);
}

static void		fill(t_var *var, t_img *img)
{
	var->p_real = var->x / img->zoom_x + img->zone.x1;
	var->p_i = var->y / img->zoom_y + img->zone.y1;
	var->z_real = 0;
	var->z_imag = 0;
	var->i = 0;
}

void			loop_man(t_img *img, t_set set, t_var *var)
{
	while (var->x < WIN_X)
	{
		var->y = 0;
		while (var->y < WIN_Y)
		{
			fill(var, img);
			while ((var->z_real * var->z_real + var->z_imag
			* var->z_imag) < 4 && var->i < img->iteration)
			{
				var->tmp = var->z_real;
				var->z_real = var->z_real * var->z_real
							- var->z_imag * var->z_imag + var->p_real;
				var->z_imag = 2 * var->z_imag * var->tmp + var->p_i;
				var->i++;
			}
			if (var->i == img->iteration)
				ft_change_color(img, var->x, var->y, (t_color){0, 0, 0});
			else
				ft_change_color(img, var->x, var->y,
						modulate_color(var->i, choose_color(set, var->i)));
			var->y++;
		}
		var->x++;
	}
}
