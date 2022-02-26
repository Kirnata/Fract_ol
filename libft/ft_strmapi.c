/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:49:12 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/15 20:54:31 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	j;
	char	*mapi;

	i = 0;
	j = ft_strlen(s);
	mapi = (char *)malloc((j + 1) * sizeof(char));
	if (mapi == NULL)
		return (0);
	while (i < j)
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
