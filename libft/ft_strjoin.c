/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:34:58 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/13 19:36:55 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{	
	char	*s3;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (s3 == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}
