/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:48:39 by ptopping          #+#    #+#             */
/*   Updated: 2022/02/26 19:55:31 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error_messages.h"

long double	count_atod(int num, char *str, int *i)
{
	while (str[*i] != '\0' && ft_isdigit(str[*i]))
	{
		num = (num * 10) + (str[*i] - '0');
		++(*i);
	}
	if (num < -9223372036854775808.0 || num > 9223372036854775807.0)
		print_help(ERR_OPT_PARMS);
	return (num);
}

double	atod(char *str)
{
	int			i;
	int			j;
	int			sign;
	long double	number;
	long double	fract_part;

	i = 0;
	j = 0;
	sign = 1;
	number = 0;
	fract_part = 0;
	if ((str[i] != '\0') && (str[i] == '-'))
	{
		sign = -1;
		++i;
	}
	number = count_atod(number, str, &i);
	if (str[i] != '\0' && str[i] == '.')
		++i;
	j = i;
	fract_part = count_atod(fract_part, str, &j);
	number += fract_part / pow(10, (j - i));
	if (number < -9223372036854775808.0 || number > 9223372036854775807.0)
		print_help(ERR_OPT_PARMS);
	return ((double)(number * sign));
}
