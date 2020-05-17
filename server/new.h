/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:06:18 by htillman          #+#    #+#             */
/*   Updated: 2019/05/06 17:31:53 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_H
# define NEW_H
# include "./libs/libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "pthread.h"
# include "./Frameworks/SDL2.framework/Headers/SDL.h"
# include "./Frameworks/SDL2_net.framework/Headers/SDL_net.h"

/* socets */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
pthread_mutex_t mutex;

typedef struct	s_data
{
	int			len;
	int			x;
	int			y;
	int			col;
}				t_data;

typedef struct	s_sdl
{
	SDL_Window	*win_ptr;
	SDL_Surface	*sur_ptr;
	SDL_Event	event;
	int			width;
	int			height;
}				t_sdl;


typedef	struct	s_p
{
	int			x;
	int			y;
}				t_p;


typedef	struct	s_win
{
	int			width;
	int			height;
}				t_win;


typedef struct	s_b
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			d;
	int			d1;
	int			d2;
	int			x;
	int			y;
	int			i;
}				t_b;
typedef struct	s_new
{
	char	*ip_adr;
	IPaddress	ip;
	TCPsocket	client;
	TCPsocket	server;
	t_data		*data_my;
	t_data		*data_client;
	int			port;
	t_win		win;
	t_sdl		sdl;
	int			net_flag;
	int			draw_fl;
	int			draw_fl_g;
	int			x_s;
	int			y_s;
	int			x_e;
	int			y_e;
	int			change_fl;
	t_data		tmp;
}				t_new;

void	ft_close(t_new *new);
void	ft_create_connection(t_new *new);
void	ft_listening(t_new *new);
void	ft_send(t_new *new);
int		ft_compare(t_data *tmp, t_data *client);
void	ft_fill_data(t_new *new);
void	ft_print_data(t_data dat);
void	ft_change_data( t_data *d);

void	*ft_render(void *data);
void	ft_draw_points(t_new *new);
void	ft_draw_screen(t_new *new);
void	ft_main_loop(t_new *new);
int				ft_ch_key(t_new *new);
void	ft_disconnect(t_new *new);
int				ft_exit_x(t_new *t);




void					ft_brasenham(t_new *k, int col);
void	ft_loop_net(t_new *new);
int	ft_connect(void *data);
void	ft_draw_triangle(t_new *t, t_data *points, int fl);

void	ft_init_sdl(t_new *t);
void	ft_surface_set_pixel(SDL_Surface *surface, int x, int y, Uint32 color);
void	ft_fill_strcut(t_data *d);


void	ft_right(t_new *new);
void	ft_left(t_new *new);
void	ft_backward(t_new *new);
void	ft_forward(t_new *new);

void	ft_clear_tri(t_new *new, t_data *del);
//exipr




#endif
