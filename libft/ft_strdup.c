/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:59:47 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/13 16:27:54 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*s1;
	char	*str2;

	s1 = (char *)str;
	str2 = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (str2 == NULL)
		return (0);
	i = 0;
	while (str[i] != 0)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
