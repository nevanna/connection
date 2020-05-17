#include "new.h"

void	ft_change_data(t_data *d)
{
	d[0].x += 20;
	d[0].y += 20;
	d[0].len = sizeof(d);
	ft_fill_strcut(d);
}

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
	new->data_my[0].x = 100;
	new->data_my[0].y = 100;
	new->data_my[0].len = sizeof(new->data_my[0]);
	new->data_my[0].col = 0xAEF100;
	ft_fill_strcut(new->data_my);
}

void	ft_send(t_new *new)
{
	SDL_Thread	*thread;

	thread = SDL_CreateThread(ft_connect, "second", (void *)new);
	if (NULL == thread)
		printf("SDL_CreateThread failed: %s\n", SDL_GetError());
	ft_draw_screen(new);
	ft_draw_points(new);
	ft_main_loop(new);
	SDL_WaitThread(thread, NULL);
}

void	ft_listening(t_new *new)
{
	ft_putendl("i am listening");
	int i;

	i = 0;
	while (1)
	{
		new->client = SDLNet_TCP_Accept(new->server);
		if (new->client)
		{
			new->data_client = (t_data *)malloc(sizeof(t_data) *(3));
			ft_bzero((void *)new->data_client, sizeof(t_data) * 3);
			break ;
		}
		i++;
		if ( i == 2147483647)
		{
				ft_close(new);
			ft_return("I am tired of waiting(( see u, bye");
		}
	}
	ft_init_sdl(new);
	ft_send(new);
}

void	ft_create_connection(t_new *new)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_return("error: sdl init");
	if (SDLNet_Init() < 0)
		ft_return("error: sdl net init");
	if (SDLNet_ResolveHost(&(new->ip), new->ip_adr, new->port) < 0)
		ft_return("error: resolv_host");
	if (!(new->server = SDLNet_TCP_Open(&new->ip)))
		ft_return("error: tcp open");
	else
	{
		ft_fill_data(new);
		ft_listening(new);
	}
}



