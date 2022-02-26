/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:40:36 by ptopping          #+#    #+#             */
/*   Updated: 2022/02/23 15:36:14 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <pthread.h>

# define WIDTH 1000
# define HEIGHT 700
# define THREAD_NUM 10
# define MANDELBROTE 1
# define JULIA 2
# define SHIP 3
# define STDERR 2

/*
** Fractal
*/

/*
** c_re           — real part of constant complex number c
** c_im           — imaginary part of constant complex number
** z_re           — real part of complex number z
** z_im           — imaginary part of complex number z
** pr             — real part of complex number p (only for Mandelbrot)
** pi             — imaginary part of complex number p (only for Mandelbrot)
** zoom           - image zoom ratio
** move_x         - rendering coordinate x of a particular pixel
** move_y         - rendering coordinate y of a particular pixel
** shift          - shift of color channels move_x or move_y
** name           - fractal type
** max_iter       — maximum iteration
** last_iter      - last iteration of the cycle fractal calculation
** color          - color shift option
*/

typedef struct s_fractal {
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	pr;
	double	pi;
	double	zoom;
	double	move_x;
	double	move_y;
	double	shift;
	int		name;
	int		max_iter;
	int		last_iter;
	int		color;
}				t_fractal;

/*
** Data
** img            — image identifier
** addr           — image
** bits_per_pixel — depth of image
** line_length    — number of bytes used to store one line of image
** endian         — little or big endian
*/

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*
** Vars
** data           — information about image
** fractal        — parameters of fractal
** mlx            — connection identifier
** win            — window identifier
*/

typedef struct s_vars {
	t_data		*data;
	t_fractal	*fractal;
	void		*mlx;
	void		*win;
}					t_vars;

/*
** Threads
** vars           — all data about fractal and mlx image
** tread          — thread ID
** y              - defines the start of the rendering area of ​​a thread
** h              - defines the height of the rendering area of ​​a thread
*/

typedef struct s_thread {
	t_vars		*vars;
	pthread_t	*thread;
	int			y;
	int			h;
}					t_thread;

/*
** Functions
*/
t_vars		*draw_window(int argc, char **argv);
t_data		*draw_image(t_vars *vars);
t_fractal	*init_fractal(int argc, char **argv);
void		*draw_pixels(void *threads);
int			do_fractal(t_fractal *fractal, int x, int y);
int			ft_julia(t_fractal fractal, int x, int y);
int			ft_mandelbrot(t_fractal fractal, int x, int y);
int			ft_ship(t_fractal fractal, int x, int y);
int			color_func(t_fractal *fractal);
void		ft_panic(char *str);
int			key_hook(int keycode, t_vars *vars);
int			mouse_hook(int keycode, int x, int y, t_vars *vars);
int			my_close(int keycode, t_vars *vars);
void		print_help(char *str);
void		draw_help(t_vars *vars);
void		draw(t_vars *vars);
int			check_params(char *str1, char *str2);
double		atod(char *str);
int			destroy(t_vars *vars);

#endif