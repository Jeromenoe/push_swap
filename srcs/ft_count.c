/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:50:03 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/10 11:33:17 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_count_med(t_list **lst_b, t_list **lst_c, int mediane, int c)
{
	int		c2;
	t_list	*lst;

	c2 = 0;
	lst = *lst_b;
	while (lst->nb > mediane)
	{
		c2++;
		lst = lst->next;
	}
	ft_lst_add(lst_c, c - c2);
	ft_lst_add(lst_c, c2);
}

void	ft_count_sec_med(t_list **lst_b, t_list **lst_c, int mediane, int c)
{
	int		c2;
	t_list	*lst;

	c2 = 0;
	lst = *lst_b;
	while (lst->nb >= mediane)
	{
		c2++;
		lst = lst->next;
	}
	ft_lst_add(lst_c, c - c2);
	ft_lst_add(lst_c, c2);
}
