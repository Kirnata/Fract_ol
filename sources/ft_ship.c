/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ship.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:45:52 by ptopping          #+#    #+#             */
/*   Updated: 2022/02/21 22:11:46 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>

int	ft_ship(t_fractal fractal, int x, int y)
{
	double	tmp_re;

	fractal.z_re = 0;
	fractal.z_im = 0;
	tmp_re = fractal.z_re;
	fractal.last_iter = 0;
	fractal.pr = 1.5 * (x + fractal.move_x - WIDTH / 1.5) \
	/ (0.5 * fractal.zoom * WIDTH);
	fractal.pi = (y + fractal.move_y - HEIGHT / 1.5) \
	/ (0.5 * fractal.zoom * HEIGHT);
	while (fractal.last_iter < fractal.max_iter)
	{
		tmp_re = fractal.z_re;
		fractal.z_re = fractal.z_re * fractal.z_re \
		- fractal.z_im * fractal.z_im + fractal.pr;
		fractal.z_im = 2 * fabs(tmp_re * fractal.z_im) + fractal.pi;
		if ((fractal.z_re * fractal.z_re + fractal.z_im * fractal.z_im) > 4)
			break ;
		fractal.last_iter++;
	}
	if (fractal.last_iter == fractal.max_iter)
		return (0);
	return (color_func(&fractal));
}
