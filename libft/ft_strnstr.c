/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:29:08 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/25 23:09:39 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		while (big[i + j] == little[j] && (i + j) < len
			&& big[i + j] && little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
		j = 0;
	}
	return (0);
}
