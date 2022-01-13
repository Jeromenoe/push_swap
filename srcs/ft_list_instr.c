/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:59:52 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/18 11:53:30 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	ft_swap(t_list *lst)
{
	int	tmp;

	if (lst && lst->next)
	{
		tmp = lst->nb;
		lst->nb = lst->next->nb;
		lst->next->nb = tmp;
	}
}

void	ft_push(t_list **src, t_list **dest)
{
	if (!(*src))
		return ;
	ft_lst_add(dest, (*src)->nb);
	(*dest)->flag = (*src)->flag;
	(*dest)->file = (*src)->file;
	if ((*src)->next)
	{
		*src = (*src)->next;
		free((*src)->prev);
		(*src)->prev = NULL;
	}
	else
	{
		free(*src);
		*src = NULL;
	}
}

void	ft_rotate(t_list **beg_lst)
{
	t_list	*lst;

	if (!(*beg_lst) || !(*beg_lst)->next)
		return ;
	lst = *beg_lst;
	lst = ft_last_elem(lst);
	lst->next = *beg_lst;
	lst->next->prev = lst;
	*beg_lst = (*beg_lst)->next;
	(*beg_lst)->prev = NULL;
	lst->next->next = NULL;
}

void	ft_reverse_rotate(t_list **beg_lst)
{
	t_list	*lst;

	if (!(*beg_lst) || !(*beg_lst)->next)
		return ;
	lst = *beg_lst;
	lst = ft_last_elem(lst);
	(*beg_lst)->prev = lst;
	lst->next = (*beg_lst);
	(*beg_lst) = (*beg_lst)->prev;
	lst->prev->next = NULL;
	(*beg_lst)->prev = NULL;
}

int		ft_check_list(t_list *lst_a, t_list *lst_b)
{
	if (lst_b)
		return (0);
	if (!lst_a)
		return (0);
	while (lst_a->next)
	{
		if (lst_a->nb > lst_a->next->nb)
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}
