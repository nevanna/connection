#include "new.h"


static void				ft_x(t_new *k, t_b *b, int col)
{
	b->d = (b->dy << 1) - b->dx;
	b->d1 = b->dy << 1;
	b->d2 = (b->dy - b->dx) << 1;

	ft_surface_set_pixel(k->sdl.sur_ptr, k->x_s, k->y_s, col);
	b->x = k->x_s + b->sx;
	b->y = k->y_s;
	while (b->i < b->dx)
	{
		if (b->d > 0)
		{
			b->d += b->d2;
			b->y += b->sy;
		}
		else
			b->d += b->d1;
		ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y, col);
		b->x += b->sx;
		b->i++;
	}
}

static void				ft_y(t_new *k, t_b *b, int col)
{
	b->d = (b->dx << 1) - b->dy;
	b->d1 = b->dx << 1;
	b->d2 = (b->dx - b->dy) << 1;
	ft_surface_set_pixel(k->sdl.sur_ptr, k->x_s, k->y_s, col);
	b->x = k->x_s;
	b->y = k->y_s + b->sy;
	while (b->i < b->dy)
	{
		if (b->d > 0)
		{
			b->d += b->d2;
			b->x += b->sx;
		}
		else
			b->d += b->d1;
		ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y, col);
		b->y += b->sy;
		b->i++;
	}
}

void					ft_brasenham(t_new *k, int col)
{
	t_b					b;

	b.i = 0;
	b.dx = (k->x_e > k->x_s) ? (k->x_e - k->x_s) : (k->x_s - k->x_e);
	b.dy = (k->y_e > k->y_s) ? (k->y_e - k->y_s) : (k->y_s - k->y_e);
	b.sx = (k->x_e >= k->x_s) ? (1) : (-1);
	b.sy = (k->y_e >= k->y_s) ? (1) : (-1);
	if (b.dy < b.dx)
		ft_x(k, &b, col);
	else
		ft_y(k, &b, col);
}
