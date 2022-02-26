/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:58:25 by ptopping          #+#    #+#             */
/*   Updated: 2022/02/21 22:42:32 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error_messages.h"
#include <mlx.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_vars	*draw_window(int argc, char **argv)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == NULL)
		ft_panic(ERR_FRACT_INIT);
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		ft_panic(ERR_FRACT_INIT);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Fractol");
	if (vars->win == NULL)
		ft_panic(ERR_WIN_INIT);
	vars->fractal = init_fractal(argc, argv);
	vars->data = draw_image(vars);
	return (vars);
}

t_data	*draw_image(t_vars *vars)
{
	vars->data = (t_data *)malloc(sizeof(t_data));
	if (vars->data == NULL)
		ft_panic(ERR_IMG_INIT);
	vars->data->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (vars->data->img == NULL)
		ft_panic(ERR_IMG_INIT);
	vars->data->addr = mlx_get_data_addr(vars->data->img, \
	&vars->data->bits_per_pixel, &vars->data->line_length, &vars->data->endian);
	if (vars->data->addr == NULL)
		ft_panic(ERR_IMG_INIT);
	draw(vars);
	return (vars->data);
}

void	draw(t_vars *vars)
{
	t_thread	threads[THREAD_NUM];
	pthread_t	tr[THREAD_NUM];
	int			i;
	int			_h;

	i = 0;
	_h = HEIGHT / THREAD_NUM;
	while (i < THREAD_NUM)
	{
		threads[i].vars = vars;
		threads[i].y = i * _h;
		threads[i].h = _h * (i + 1);
		pthread_create(&(tr[i]), NULL, draw_pixels, (void *)&threads[i]);
		++i;
	}
	i = 0;
	while (i < THREAD_NUM)
	{
		pthread_join(tr[i], NULL);
		++i;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
}

void	*draw_pixels(void *threads)
{
	int			x;
	int			col;
	t_thread	*thread;
	t_vars		*vars;
	int			y;

	x = 0;
	col = 0;
	thread = (t_thread *)threads;
	vars = thread->vars;
	y = thread->y;
	while (y < thread->h)
	{
		while (x < WIDTH)
		{
			col = do_fractal(vars->fractal, x, y);
			my_mlx_pixel_put(vars->data, x, y, col);
			x++;
		}
		++y;
		x = 0;
	}
	return (NULL);
}
