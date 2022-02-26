/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:23:11 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/24 04:54:57 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *set, int c)
{	
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*all_check(char const *s1, char const *set, int end)
{
	int		i;
	char	*s2;
	int		begin;

	begin = 0;
	i = 0;
	while (s1[begin] && begin < end && ft_check(set, s1[begin]))
		begin++;
	if (begin == end)
	{
		s2 = (char *)malloc(1 * sizeof(char));
		s2[0] = '\0';
		return (s2);
	}
	while (end > begin && ft_check(set, s1[end - 1]))
		end--;
	s2 = (char *)malloc((end - begin + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (begin < end)
		s2[i++] = s1[begin++];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	int		i;

	begin = 0;
	end = 0;
	i = 0;
	if (!set)
		return (ft_strdup(s1));
	else
	{	
		end = ft_strlen(s1);
		return (all_check(s1, set, end));
	}
}
