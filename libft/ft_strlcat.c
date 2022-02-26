/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:03:44 by ptopping          #+#    #+#             */
/*   Updated: 2022/02/23 15:49:48 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	if (size < dst_len)
		src_len += size;
	else
		src_len += dst_len;
	while (src[i] != '\0' && dst != src && dst_len < size - 1)
	{
		dst[dst_len] = src[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (src_len);
}
