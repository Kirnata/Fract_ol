/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:58:11 by ptopping          #+#    #+#             */
/*   Updated: 2021/10/21 14:58:38 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_l)
{
	t_list	*last;

	if (!lst || !new_l)
		return ;
	if (!(*lst))
		*lst = new_l;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new_l;
	}
}
