/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:45:08 by ptopping          #+#    #+#             */
/*   Updated: 2022/02/17 04:03:55 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	do_fractal(t_fractal *fractal, int x, int y)
{
	if (fractal->name == MANDELBROTE)
		return (ft_mandelbrot(*fractal, x, y));
	else if (fractal->name == JULIA)
		return (ft_julia(*fractal, x, y));
	else if (fractal->name == SHIP)
		return (ft_ship(*fractal, x, y));
	return (0);
}
