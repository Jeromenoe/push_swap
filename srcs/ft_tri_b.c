/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:04:20 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/03 10:24:40 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_tri_2_btoa(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_b)->nb < (*lst_b)->next->nb)
		ft_sb(lst_a, lst_b);
	ft_pa(lst_a, lst_b);
	ft_pa(lst_a, lst_b);
}

void	ft_tri_3_btoa(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_b)->nb < (*lst_b)->next->nb)
		ft_sb(lst_a, lst_b);
	ft_pa(lst_a, lst_b);
	if ((*lst_b)->nb < (*lst_b)->next->nb)
		ft_sb(lst_a, lst_b);
	ft_pa(lst_a, lst_b);
	if ((*lst_a)->nb > (*lst_a)->next->nb)
		ft_sa(lst_a, lst_b);
	ft_pa(lst_a, lst_b);
	if ((*lst_a)->nb > (*lst_a)->next->nb)
		ft_sa(lst_a, lst_b);
}

void	ft_tri_inf3_btoa(t_list **lst_a, t_list **lst_b, int len)
{
	if (len == 1)
		ft_pa(lst_a, lst_b);
	else if (len == 2)
		ft_tri_2_btoa(lst_a, lst_b);
	else if (len == 3)
		ft_tri_3_btoa(lst_a, lst_b);
}
