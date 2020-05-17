#include "new.h"

void	ft_fill_strcut(t_data *d)
{
	d[1].x = d[0].x - 55;
	d[1].y = d[0].y - 60;
	d[1].len = sizeof(d[1]);
	d[2].x = d[0].x - 55;
	d[2].y = d[0].y + 60;
	d[2].len = sizeof(d[2]);
}

void	ft_fill_data(t_new *new)
{
	new->data_my = (t_data *)malloc(sizeof(t_data) *(3));
	new->data_my[0].x = 200;
	new->data_my[0].y = 100;
	new->data_my[0].len = sizeof(new->data_my[0]);

	new->data_my[0].col = 0xFF0000;
	ft_bzero(&new->tmp, sizeof(t_data));
	ft_fill_strcut(new->data_my);
}

void	ft_create_connection(t_new *new)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_return("error: sdl init");
	if (new->net_flag == 2)
	{
		if (SDLNet_Init() < 0)
			ft_return("error: sdl net init");
		if (SDLNet_ResolveHost(&(new->ip), new->ip_adr, new->port) < 0)
			ft_return("error: resolv_host");
		if (!(new->client = SDLNet_TCP_Open(&new->ip)))
			ft_return("error: tcp open");
		else
		{
			new->data_serv = (t_data *)malloc(sizeof(t_data) *(3));
			ft_bzero((void *)new->data_serv, sizeof(t_data) * 3);
			ft_putendl("start tcp session");
		}
	}
	ft_init_sdl(new);
	ft_fill_data(new);
	ft_send(new);
}



void	ft_send(t_new *new)
{
	SDL_Thread	*thread;

	if (new->net_flag == 2)
	{
		thread = SDL_CreateThread(ft_connect, "second", (void *)new);
		if (NULL == thread)
			printf("SDL_CreateThread failed: %s\n", SDL_GetError());
	}
	ft_draw_screen(new);
	ft_draw_points(new);
	ft_main_loop(new);
	if (new->net_flag == 2)
		SDL_WaitThread(thread, NULL);

}

void ft_init_draw(t_new *new)
{
	ft_create_connection(new);
}




