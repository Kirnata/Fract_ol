/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:57:19 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/16 21:22:23 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	c;

	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	if (nb < 0 && nb != -2147483648)
	{
		nb = nb * (-1);
		write(fd, "-", 1);
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	if (nb >= 0 && nb < 10)
	{
		c = nb + '0';
		write(fd, &c, 1);
	}
}
