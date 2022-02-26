/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:49:14 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/13 15:02:23 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*(unsigned char *)(arr + i) == (unsigned char)c)
			return ((void *)arr + i);
		i++;
	}
	return (NULL);
}
