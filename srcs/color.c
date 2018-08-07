/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 07:59:35 by golliet           #+#    #+#             */
/*   Updated: 2018/08/07 16:54:31 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_change_color(t_img *img, int x, int y, t_color color)
{
	int nb;

	if (x < 0 || y < 0)
		return ;
	if (x >= WIN_X || y >= WIN_Y)
		return ;
	nb = y * img->size_line + (img->bit_p / 8) * x;
	img->zone_mem[nb] = color.blue;
	img->zone_mem[nb + 1] = color.green;
	img->zone_mem[nb + 2] = color.red;
}

t_set			init_color(int i)
{
	t_set tab[7];

	tab[0] = (t_set){(t_color){204, 255, 255},
	(t_color){102, 204, 255}, (t_color){51, 153, 255},
	(t_color){0, 0, 255}, (t_color){0, 52, 205}, (t_color){255, 255, 0}};
	tab[1] = (t_set){(t_color){255, 0, 0},
	(t_color){255, 60, 44}, (t_color){250, 115, 3},
	(t_color){253, 57, 135}, (t_color){64, 64, 64}, (t_color){0, 0, 0}};
	tab[2] = (t_set){(t_color){3, 3, 254},
	(t_color){50, 50, 200}, (t_color){80, 80, 200},
	(t_color){110, 110, 200}, (t_color){140, 140, 210}, (t_color){180, 180, 210}};
	tab[3] = (t_set){(t_color){250, 0, 0},
	(t_color){0, 255, 0}, (t_color){0, 0, 255},
	(t_color){253, 223, 0}, (t_color){253, 0, 200}, (t_color){12, 255, 203}};
	tab[4] = (t_set){(t_color){180, 180, 180},
	(t_color){203, 0, 0}, (t_color){120, 120, 120},
	(t_color){203, 0, 0}, (t_color){60, 60, 60}, (t_color){203, 0, 0}};
	tab[5] = (t_set){(t_color){180, 180, 180},
	(t_color){0, 200, 0}, (t_color){120, 120, 120},
	(t_color){0, 200, 0}, (t_color){60, 60, 60}, (t_color){0, 200, 0}};
	tab[6] = (t_set){(t_color){180, 180, 180},
	(t_color){0, 0, 200}, (t_color){120, 120, 120},
	(t_color){0, 0, 200}, (t_color){60, 60, 60}, (t_color){0, 0, 200}};
	return (tab[i]);
}

t_color			choose_color(t_set col, int n)
{
	if (n % 6 == 1)
		return (col.c1);
	if (n % 6 == 2)
		return (col.c2);
	if (n % 6 == 3)
		return (col.c3);
	if (n % 6 == 4)
		return (col.c4);
	if (n % 6 == 5)
		return (col.c5);
	return (col.c0);
}

t_color			modulate_color(int n, t_color color)
{
	t_color tmp;

	if (n == 0)
		n = 1;
	tmp.red = color.red - color.red / n;
	tmp.blue = color.blue - color.blue / n;
	tmp.green = color.green - color.green / n;
	return (tmp);
}
