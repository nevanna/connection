#include "new.h"
void	ft_clear_tri(t_new *new, t_data *del)
{
	ft_draw_triangle(new, del, 2);
}

void	ft_forward(t_new *new)
{
	SDL_mutex *mutex;

	mutex = SDL_CreateMutex();
	ft_clear_tri(new, new->data_my);
	SDL_LockMutex(mutex);
	new->data_my[0].y -= 5;
	if (new->data_my[0].y < 60)
		new->data_my[0].y = 60;
	ft_fill_strcut(new->data_my);
	SDL_UnlockMutex(mutex);
	ft_draw_triangle(new, new->data_my, 0);
	///ft_draw_points(new);
	SDL_DestroyMutex(mutex);
}
void	ft_backward(t_new *new)
{
	SDL_mutex *mutex;

	mutex = SDL_CreateMutex();
	ft_clear_tri(new, new->data_my);
	SDL_LockMutex(mutex);
	new->data_my[0].y += 5;
	if (new->data_my[0].y > new->win.height - 60)
		new->data_my[0].y = new->win.height - 60;
	ft_fill_strcut(new->data_my);
	SDL_UnlockMutex(mutex);
	ft_draw_triangle(new, new->data_my, 0);
	//ft_draw_points(new);
	SDL_DestroyMutex(mutex);
}

void	ft_left(t_new *new)
{
	SDL_mutex *mutex;

	mutex = SDL_CreateMutex();
	ft_clear_tri(new, new->data_my);
	SDL_LockMutex(mutex);
	new->data_my[0].x -= 5;
	if (new->data_my[0].x < 55)
		new->data_my[0].x = 55;
	ft_fill_strcut(new->data_my);
	SDL_UnlockMutex(mutex);
	ft_draw_triangle(new, new->data_my, 0);
	//ft_draw_points(new);
	SDL_DestroyMutex(mutex);
}

void	ft_right(t_new *new)
{
	SDL_mutex *mutex;

	mutex = SDL_CreateMutex();
	ft_clear_tri(new, new->data_my);
	SDL_LockMutex(mutex);
	new->data_my[0].x += 5;
	if (new->data_my[0].x > new->win.width)
		new->data_my[0].x = new->win.width - 1;
	ft_fill_strcut(new->data_my);
	SDL_UnlockMutex(mutex);
	ft_draw_triangle(new, new->data_my, 0);
	//ft_draw_points(new);
	SDL_DestroyMutex(mutex);
}
