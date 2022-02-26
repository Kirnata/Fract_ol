/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:46:59 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/13 23:34:05 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	buffer = (void *)malloc(count * size);
	if (buffer == NULL)
		return (NULL);
	ft_bzero(buffer, count * size);
	return (buffer);
}
