
#include "fractol.h"

void            ft_change_color(t_img *img, int x, int y, t_color color)
{
	int nb;

	if (x < 0 || y < 0)
		return ;
	if (x >= WIN_X || y >= WIN_Y)
		return ;
	nb = y * img->size_line + (img->bit_p/8) * x;
	img->zone_mem[nb] = color.blue;
	img->zone_mem[nb + 1] = color.green;
	img->zone_mem[nb + 2] = color.red;
}

t_set		init_color(int i)
{
	t_set tab[6];

	tab[0] = (t_set){(t_color){204,255,255},(t_color){102,204,255},(t_color){51,153,255},(t_color){0,0,255},(t_color){0,52,205},(t_color){255,255,0}};
	tab[1] = (t_set){(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0}};
	tab[2] = (t_set){(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0}};
	tab[3] = (t_set){(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0}};
	tab[4] = (t_set){(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0}};
	tab[5] = (t_set){(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0},(t_color){0,0,0}};
	return (tab[i]);
}

t_color		choose_color(t_set col, int n)
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

t_color		modulate_color(int n, t_color color, int iter)
{
	t_color tmp;
	tmp.red =  n * color.red / iter;
	tmp.blue = n * color.blue / iter;
	tmp.green = n * color.green / iter;
	return (tmp);
}