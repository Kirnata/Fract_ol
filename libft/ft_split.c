/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:48:02 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/24 04:45:10 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	ft_fill(char *word, char const *s, int i, char c)
{	
	int	k;

	k = 0;
	while (s[i] != c && s[i] != '\0')
	{
		word[k] = s[i];
		k++;
		i++;
	}
	word[k] = '\0';
}

static int	bla(char ***pointers, char const *s, char c)
{
	int		count_w;

	count_w = count_words(s, c);
	*pointers = (char **)malloc((count_w + 1) * sizeof(char *));
	if (pointers == NULL)
	{
		free(pointers);
		return (0);
	}
	return (count_w);
}

static char	**func_free(char **pointers)
{
	int	i;

	i = 0;
	while (pointers[i])
	{
		free(pointers[i]);
		i++;
	}
	free(pointers);
	return (NULL);
}

//	counter[0] = i - счетчик по s
//	counter[1] = pop - по poiters
//	counter[2] = count

char	**ft_split(char const *s, char c)
{
	char	**pointers;
	int		counter[3];
	char	*pas;
	size_t	len;

	ft_memset(counter, 0, sizeof(counter));
	counter[2] = bla(&pointers, s, c);
	while (counter[1] < counter[2])
	{
		while (s[counter[0]] == c)
			counter[0]++;
		pas = ft_strchr(&s[counter[0]], c);
		if (pas == NULL)
			len = ft_strlen(&s[counter[0]]);
		else
			len = pas - &s[counter[0]];
		pointers[counter[1]] = (char *)malloc((len + 1) * sizeof(char));
		if (pointers[counter[1]] == NULL)
			return (func_free(pointers));
		ft_fill(pointers[counter[1]], s, counter[0], c);
		counter[1]++;
		counter[0] += len;
	}
	pointers[counter[1]] = NULL;
	return (pointers);
}
