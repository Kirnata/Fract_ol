/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:08:58 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/21 14:42:20 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	func_j(char const *s, char *news, size_t size, unsigned int start)
{
	int	j;

	j = 0;
	while (size-- > 0)
		news[j++] = s[start++];
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t size)
{
	char			*news;
	unsigned int	j;
	unsigned int	len_s;

	j = 0;
	len_s = (unsigned int)ft_strlen(s);
	if (start > len_s - 1)
	{
		news = (char *)malloc(1);
		if (news == NULL)
			return (NULL);
	}
	else
	{	
		if (size > len_s - start)
			size = len_s - start;
		news = (char *)malloc((size)
				* sizeof(char) + 1);
		if (news == NULL)
			return (NULL);
		j = func_j(s, news, size, start);
	}
	news[j] = '\0';
	return (news);
}
