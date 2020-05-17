#include "new.h"

int	ft_compare(t_data *tmp, t_data *serv)
{
	if ( tmp->x - serv[0].x != 0 || tmp->y - serv[0].y != 0 || tmp->len - serv[0].len != 0)
	{
		// ft_memcpy(&serv[0], tmp, sizeof(t_data));
		// serv[0].col =0xAEF100;
		// ft_fill_strcut(serv);
		// ft_bzero(tmp, sizeof(t_data));
		return (1);
	}
	else
		ft_bzero(tmp, sizeof(t_data));
	return (0);
}

void ft_loop_net(t_new *new)
{
	int rez_recv = 0;
	SDL_mutex *mutex;

	mutex = SDL_CreateMutex();
	while (1)
	{
		SDLNet_TCP_Send(new->client, &new->data_my[0], 16);
		rez_recv = SDLNet_TCP_Recv(new->client, &new->tmp, 16);
		if (rez_recv > 0)
		{
			SDL_LockMutex(mutex);
			new->change_fl = ft_compare(&new->tmp, &new->data_serv[0]);
			SDL_UnlockMutex(mutex);
		}
		SDL_Delay(100);
	}
	SDL_DestroyMutex(mutex);
}

int ft_connect(void *data)
{
	t_new *new;
	new = (t_new*)data;
	ft_loop_net(new);
	return(1);
}
