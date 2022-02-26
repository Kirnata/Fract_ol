/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:51:50 by ptopping          #+#    #+#             */
/*   Updated: 2022/02/21 13:28:26 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	color_func(t_fractal *fractal)
{
	int	intens;
	int	my_color;

	intens = (0xFF * ((float)fractal->last_iter / (float)fractal->max_iter));
	my_color = ((intens << 16) * ((fractal->color >> 2) & 1) \
	| (intens << 8) * ((fractal->color >> 1) & 1) \
	| intens * (fractal->color & 1));
	return (my_color);
}
