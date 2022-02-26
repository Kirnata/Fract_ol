/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:37:57 by ptopping          #+#    #+#             */
/*   Updated: 2022/02/23 11:49:19 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "error_messages.h"

void	print_help(char *str)
{
	ft_putendl_fd(str, 1);
	ft_putendl_fd("Avaliable parametres:", 1);
	ft_putendl_fd("-> Mandelbrot", 1);
	ft_putendl_fd("-> Julia + optional parameters: c_real, c_image", 1);
	ft_putendl_fd("-> Burning_ship", 1);
	exit(1);
}

void	ft_panic(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	check_param(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			++i;
		else if (str[i] == '.' || str[i] == '+' || str[i] == '-')
			++i;
		else
			return (0);
	}
	return (1);
}

int	check_params(char *str1, char *str2)
{
	if (check_param(str1) && check_param(str2))
		return (1);
	else
		return (0);
}
