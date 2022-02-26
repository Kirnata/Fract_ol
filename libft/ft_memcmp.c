/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:04:40 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/14 00:24:36 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t size)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)arr1;
	s2 = (unsigned char *)arr2;
	i = 0;
	if (!arr1 && !arr2)
		return (0);
	while ((i < size))
	{
		if ((*(s1 + i)) != (*(s2 + i)))
			return ((*(s1 + i)) - (*(s2 + i)));
		i++;
	}
	return (0);
}
