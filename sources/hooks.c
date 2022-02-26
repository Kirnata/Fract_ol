/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:21:07 by ptopping          #+#    #+#             */
/*   Updated: 2022/02/23 12:19:31 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_macos.h"

int	ft_shift(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_UP)
		fractal->move_y -= fractal->shift;
	else if (keycode == KEY_DOWN)
		fractal->move_y += fractal->shift;
	else if (keycode == KEY_LEFT)
		fractal->move_x -= fractal->shift;
	else if (keycode == KEY_RIGHT)
		fractal->move_x += fractal->shift;
	return (0);
}

int	ft_zoom(int keycode, t_fractal *fractal)
{
	if (keycode == SCROLL_UP)
		fractal->zoom *= 0.9;
	else if (keycode == SCROLL_DOWN)
		fractal->zoom *= 1.1;
	return (0);
}

int	ft_iter(int keycode, t_fractal *fractal)
{
	if (keycode == PLUS && fractal->max_iter <= 500)
		fractal->max_iter *= 1.5;
	else if (keycode == MINUS && fractal->max_iter >= 3)
		fractal->max_iter /= 1.5;
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (keycode == ESC)
		destroy(vars);
	else if (keycode == KEY_UP || keycode == KEY_DOWN \
	|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		ft_shift(keycode, vars->fractal);
	else if (keycode == PLUS || keycode == MINUS)
		ft_iter(keycode, vars->fractal);
	else if (keycode == SPACE)
		vars->fractal->color += 1;
	draw(vars);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == SCROLL_DOWN)
	{
		ft_zoom(keycode, vars->fractal);
		vars->fractal->move_x += (x - WIDTH / 2 + vars->fractal->move_x) * 0.1;
		vars->fractal->move_y += (HEIGHT / 2 - y + vars->fractal->move_y) * 0.1;
	}
	else if (keycode == SCROLL_UP)
	{
		vars->fractal->move_x -= (x - WIDTH / 2 + vars->fractal->move_x) * 0.1;
		vars->fractal->move_y -= (HEIGHT / 2 - y + vars->fractal->move_y) * 0.1;
		ft_zoom(keycode, vars->fractal);
	}
	draw(vars);
	return (0);
}
