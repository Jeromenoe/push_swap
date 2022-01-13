/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:03:09 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/03 10:24:19 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void		ft_loop(t_list **lst_a, t_list **lst_b, t_data *d)
{
	int i;

	i = -1;
	while (++i < d->len)
	{
		if (i < d->len - 1 && ft_is_inf_b(*lst_b, d->len - i, d->mediane) == 0
				&& ft_is_inf_b(*lst_b, d->len - i + 1, d->mediane) == 1)
			ft_sb(lst_a, lst_b);
		else if ((*lst_b)->nb >= d->mediane)
		{
			ft_pa(lst_a, lst_b);
			(d->c)++;
		}
		else
		{
			if (ft_is_inf_b(*lst_b, d->len - i, d->mediane) == 0)
				ft_rb(lst_a, lst_b);
			else
				(d->c2)++;
		}
	}
}

void			ft_b_to_a(t_list **lst_a, t_list **lst_b, t_list **lst_c)
{
	int		i;
	t_data	d;

	if ((d.len = (*lst_c)->nb) <= 3)
	{
		ft_lst_c_del(lst_c);
		ft_tri_inf3_btoa(lst_a, lst_b, d.len);
		if (*lst_c)
			return (ft_b_to_a(lst_a, lst_b, lst_c));
		return ;
	}
	d.mediane = ft_median(*lst_b, d.len);
	i = -1;
	d.c = 0;
	d.c2 = 0;
	ft_loop(lst_a, lst_b, &d);
	i = -1;
	while (++i < d.len - d.c - d.c2)
		ft_rrb(lst_a, lst_b);
	ft_lst_c_del(lst_c);
	if (d.len > 0)
		ft_lst_add(lst_c, d.len - d.c);
	ft_a_to_b(lst_a, lst_b, lst_c, d.c);
}
