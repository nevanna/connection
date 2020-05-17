#include "new.h"

void	ft_draw_triangle(t_new *t, t_data *points, int fl)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		t->x_s = points[i].x;
		t->y_s = points[i].y;
		j = i + 1;
		while (j < 3)
		{
			t->x_e = points[j].x;
			t->y_e = points[j].y;
			if (fl)
				ft_brasenham(t, 0xA668D5);
			else
				ft_brasenham(t, points[0].col);
			j++;
		}
		i++;
	}
	SDL_UpdateWindowSurface(t->sdl.win_ptr);
}


void ft_draw_points(t_new *new)
{

	SDL_FillRect(new->sdl.sur_ptr, NULL, SDL_MapRGB(new->sdl.sur_ptr->format, 0xA6, 0x68, 0xD5));
	ft_draw_triangle(new, new->data_my, 0);
	ft_draw_triangle(new, new->data_client, 0);

}

void	ft_disconnect(t_new *new)
{
	new->net_flag = -1;
}


void	ft_draw_screen(t_new *new)
{
	new->sdl.win_ptr = SDL_CreateWindow("TRY ANGLE SERVER", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, new->win.width, new->win.height, SDL_WINDOW_RESIZABLE );
	if (new->sdl.win_ptr == NULL)
		ft_return(ft_strjoin("Error. Window could not be created!", SDL_GetError()));
	else
	{
		new->sdl.sur_ptr = SDL_GetWindowSurface(new->sdl.win_ptr);
		SDL_FillRect(new->sdl.sur_ptr, NULL, SDL_MapRGB(new->sdl.sur_ptr->format, 0xA6, 0x68, 0xD5));
	}
}

void	ft_main_loop(t_new *new)
{
	SDL_mutex *mutex;
	mutex = SDL_CreateMutex();
	while(1)
	{
		while(SDL_PollEvent(&(new->sdl.event)))
		{
			if(new->sdl.event.type == SDL_QUIT || (new->sdl.event.type == SDL_KEYDOWN && new->sdl.event.key.keysym.sym == SDLK_ESCAPE))
				ft_exit_x(new);
			else if (new->sdl.event.type == SDL_KEYDOWN)
				ft_ch_key(new);
		}
		if (new->change_fl)
		{
			ft_clear_tri(new, new->data_client);
			SDL_LockMutex(mutex);
			ft_memcpy(&new->data_client[0], &new->tmp, sizeof(t_data));
			new->data_client[0].col =0xFF0000;
			ft_fill_strcut(new->data_client);
			ft_bzero(&new->tmp, sizeof(t_data));
			//ft_draw_points(new);
			new->change_fl = 0;
			SDL_UnlockMutex(mutex);
			ft_draw_triangle(new, new->data_client, 0);
		}
		SDL_Delay(100);
		SDL_UpdateWindowSurface(new->sdl.win_ptr);
	}
		SDL_DestroyMutex(mutex);
}


