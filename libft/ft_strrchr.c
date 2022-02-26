/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:45:35 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/16 22:34:45 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*buff;

	i = 0;
	buff = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			buff = ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)ch)
		buff = ((char *)(str + i));
	return (buff);
}
