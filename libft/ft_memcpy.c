/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:15:04 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/13 14:03:06 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest && !source)
		return (0);
	while (i < size)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(source + i);
		i++;
	}
	return (dest);
}
