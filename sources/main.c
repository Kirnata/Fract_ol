/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:31:38 by ptopping          #+#    #+#             */
/*   Updated: 2022/02/23 12:19:21 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error_messages.h"
#include "key_macos.h"

int	destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc == 2 || (argc == 4 && check_params(argv[2], argv[3])))
	{
		vars = draw_window(argc, argv);
		mlx_key_hook(vars->win, key_hook, vars);
		mlx_mouse_hook(vars->win, mouse_hook, vars);
		mlx_hook(vars->win, ON_DESTROY, 1L << 13, destroy, vars);
		mlx_loop(vars->mlx);
	}
	print_help(ERR_FEW_ARGS);
	return (0);
}
