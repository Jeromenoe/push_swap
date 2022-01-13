/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:55:03 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/03 10:24:30 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_little_tri(t_list **lst_a, t_list **lst_b)
{
	int max;
	int len;

	len = ft_lst_len(*lst_a);
	max = ft_max(*lst_a);
	if (len == 2)
	{
		if ((*lst_a)->nb > (*lst_a)->next->nb)
			ft_sa(lst_a, lst_b);
	}
	else if (len == 3)
	{
		if ((*lst_a)->nb == max)
			ft_ra(lst_a, lst_b);
		else if ((*lst_a)->next->nb == max)
			ft_rra(lst_a, lst_b);
		if ((*lst_a)->nb > (*lst_a)->next->nb)
			ft_sa(lst_a, lst_b);
	}
}

void	ft_tri_3_a_bis(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a)->nb > (*lst_a)->next->nb)
	{
		if ((*lst_b && (*lst_b)->next && (*lst_b)->nb < (*lst_b)->next->nb))
			ft_ss(lst_a, lst_b);
		else
			ft_sa(lst_a, lst_b);
	}
	if ((*lst_b && (*lst_b)->next && (*lst_b)->nb < (*lst_b)->next->nb))
		ft_sb(lst_a, lst_b);
	ft_rr(lst_a, lst_b);
}

void	ft_tri_3_a(t_list **lst_a, t_list **lst_b)
{
	if (ft_is_tri_a(*lst_a, 3))
		return ;
	ft_tri_3_a_bis(lst_a, lst_b);
	if ((*lst_a)->nb > (*lst_a)->next->nb)
	{
		if (*lst_b && (*lst_b)->next && (*lst_b)->nb < (*lst_b)->next->nb)
			ft_ss(lst_a, lst_b);
		else
			ft_sa(lst_a, lst_b);
	}
	ft_rrr(lst_a, lst_b);
	if ((*lst_a)->nb > (*lst_a)->next->nb)
	{
		if (*lst_b && (*lst_b)->next && (*lst_b)->nb < (*lst_b)->next->nb)
			ft_ss(lst_a, lst_b);
		else
			ft_sa(lst_a, lst_b);
	}
}

void	ft_tri_inf3_a(t_list **lst_a, t_list **lst_b, int len)
{
	if (len == 2)
	{
		if ((*lst_a)->nb > (*lst_a)->next->nb)
		{
			if (*lst_b && (*lst_b)->next && (*lst_b)->nb < (*lst_b)->next->nb)
				ft_ss(lst_a, lst_b);
			else
				ft_sa(lst_a, lst_b);
		}
	}
	else if (len == 3)
		ft_tri_3_a(lst_a, lst_b);
}
