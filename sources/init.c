/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:27:21 by ptopping          #+#    #+#             */
/*   Updated: 2022/02/23 14:20:08 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "error_messages.h"

int	set_name(t_fractal *fractal, int argc, char **argv)
{
	if (argc == 2 && ft_strncmp(argv[1], "Mandelbrot\0", 11) == 0)
		fractal->name = MANDELBROTE;
	else if (argc == 2 && ft_strncmp(argv[1], "Burning_ship\0", 10) == 0)
		fractal->name = SHIP;
	else if (argc == 2 && ft_strncmp(argv[1], "Julia\0", 6) == 0)
	{
		fractal->name = JULIA;
		fractal->c_re = -0.4;
		fractal->c_im = 0.6;
	}
	else if (argc == 4 && ft_strncmp(argv[1], "Julia\0", 6) == 0)
	{
		fractal->name = JULIA;
		fractal->c_re = atod(argv[2]);
		fractal->c_im = atod(argv[3]);
	}
	else
		fractal->name = -1;
	return (0);
}

void	set_defaults(t_fractal *fractal)
{
	fractal->c_re = 0;
	fractal->c_im = 0;
	fractal->z_re = 0;
	fractal->z_im = 0;
	fractal->pr = 0;
	fractal->pi = 0;
	fractal->max_iter = 50;
	fractal->zoom = 1;
	fractal->last_iter = 0;
	fractal->color = 4;
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->shift = 20;
}

t_fractal	*init_fractal(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (fractal == NULL)
		ft_panic(ERR_FRACT_INIT);
	set_defaults(fractal);
	set_name(fractal, argc, argv);
	if (fractal->name == -1)
		print_help("Invalid name of fractal, try again)");
	return (fractal);
}

int	do_fractol(t_fractal *fractal, int x, int y)
{
	if (fractal->name == MANDELBROTE)
		return (ft_mandelbrot(*fractal, x, y));
	else if (fractal->name == JULIA)
		return (ft_julia(*fractal, x, y));
	else if (fractal->name == SHIP)
		return (ft_ship(*fractal, x, y));
	return (0);
}
