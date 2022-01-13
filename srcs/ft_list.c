/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:49:46 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/18 11:43:46 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list	*ft_create_list(int nb)
{
	t_list	*lst;

	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	lst->nb = nb;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_last_elem(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lst_add(t_list **lst, long long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		ft_exit_a(lst);
	if (!(*lst))
		*lst = ft_create_list(nb);
	else
	{
		(*lst)->prev = ft_create_list(nb);
		(*lst)->prev->next = *lst;
		*lst = (*lst)->prev;
	}
}

int		ft_min(t_list *lst)
{
	int min;

	min = lst->nb;
	while (lst)
	{
		if (min > lst->nb)
			min = lst->nb;
		lst = lst->next;
	}
	return (min);
}

int		ft_max(t_list *lst)
{
	int max;

	max = lst->nb;
	while (lst)
	{
		if (max < lst->nb)
			max = lst->nb;
		lst = lst->next;
	}
	return (max);
}
