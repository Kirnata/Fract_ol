/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:03:22 by ptopping          #+#    #+#             */
/*   Updated: 2022/02/21 13:38:29 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	ft_mandelbrot(t_fractal fractal, int x, int y)
{
	double	tmp_re;

	fractal.z_re = 0;
	fractal.z_im = 0;
	tmp_re = fractal.z_re;
	fractal.last_iter = 0;
	fractal.pr = 1.5 * (x + fractal.move_x - WIDTH / 2) \
	/ (0.5 * fractal.zoom * WIDTH);
	fractal.pi = (y + fractal.move_y - HEIGHT / 2) \
	/ (0.5 * fractal.zoom * HEIGHT);
	while (fractal.last_iter < fractal.max_iter)
	{
		tmp_re = fractal.z_re;
		fractal.z_re = fractal.z_re * fractal.z_re \
		- fractal.z_im * fractal.z_im + fractal.pr;
		fractal.z_im = 2 * tmp_re * fractal.z_im + fractal.pi;
		if ((fractal.z_re * fractal.z_re + fractal.z_im * fractal.z_im) > 4)
			break ;
		fractal.last_iter++;
	}
	if (fractal.last_iter == fractal.max_iter)
		return (0);
	return (color_func(&fractal));
}
