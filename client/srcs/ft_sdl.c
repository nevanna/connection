#include "new.h"


void	ft_surface_set_pixel(SDL_Surface *surface, int x, int y, Uint32 color)
{
	Uint32		*target_pixel;

	if (x < 0 || y < 0 || x >= surface->w || y >= surface->h)
		return ;
	target_pixel = (Uint32 *)((Uint8 *)surface->pixels + y *
		surface->pitch + x * sizeof(*target_pixel));
	*target_pixel = color;
}

void	ft_print_data(t_data dat)
{
	printf("x->%d, y->%d len->%d\n",dat.x, dat.y, dat.len);
}

void	ft_close(t_new *new)
{
	if (new->net_flag == 2)
	{
		SDLNet_TCP_Close(new->client);
		SDLNet_Quit();
	}
	SDL_Quit();
}

void	ft_init_sdl(t_new *t)
{
	t->win.height = 1000;
	t->win.width = 1200;
	t->sdl.win_ptr = NULL;
	t->sdl.sur_ptr = NULL;
	ft_bzero(&t->tmp, sizeof(t_data));

}

int				ft_exit_x(t_new *t)
{
	ft_close(t);
	exit(1);
	return (0);
}
void	ft_disconnect(t_new *new)
{
	new->net_flag = -1;
}

int				ft_ch_key(t_new *new)
{
	if (new->sdl.event.key.keysym.sym == SDLK_x)
		ft_disconnect(new);
	else if (new->sdl.event.key.keysym.sym == SDLK_w)
		ft_forward(new);
	else if (new->sdl.event.key.keysym.sym == SDLK_s)
		ft_backward(new);
	else if (new->sdl.event.key.keysym.sym == SDLK_a)
		ft_left(new);
	else if (new->sdl.event.key.keysym.sym == SDLK_d)
		ft_right(new);
	return (0);
}
