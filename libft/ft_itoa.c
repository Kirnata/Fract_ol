/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:37:04 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/21 19:41:54 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long new)
{
	int	count;

	count = 0;
	if (new == 0)
		count++;
	while (new > 0)
	{	
		new = new / 10;
		count++;
	}	
	return (count);
}

static char	*ft_dopfunc(int count, int flag, char *itoa, long new)
{
	while (count + flag >= 0)
	{
		itoa[count + flag] = (new % 10 + '0');
		new = new / 10;
		count--;
	}
	if (flag == 1)
		itoa[0] = '-';
	return (itoa);
}

char	*ft_itoa(int nbr)
{
	long	new;
	int		flag;
	int		count;
	char	*itoa;

	new = (long)nbr;
	flag = 0;
	if (new < 0)
	{
		flag = 1;
		new *= (-1);
	}
	count = ft_count(new);
	itoa = (char *)malloc((count + flag) * sizeof(char) + 1);
	if (itoa == NULL)
		return (0);
	if (nbr == 0)
		itoa[0] = '0';
	itoa[count + flag] = '\0';
	count--;
	ft_dopfunc(count, flag, itoa, new);
	return (itoa);
}
