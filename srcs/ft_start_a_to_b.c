/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:51:07 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/10 11:34:34 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void		ft_loop(t_list **lst_a, t_list **lst_b, t_data *d)
{
	int i;

	i = -1;
	while (++i < d->len
			&& !ft_is_sup_a(*lst_a, ft_lst_len(*lst_a), d->mediane))
	{
		if ((*lst_a)->nb <= d->mediane)
		{
			if (d->len > 15 && (*lst_a)->nb < d->second_mediane
					&& ft_is_sup_b_start(*lst_b, ft_lst_len(*lst_b),
						d->second_mediane) == 0)
				while ((*lst_b)->nb >= d->second_mediane && ++(d->c2))
					ft_rb(lst_a, lst_b);
			ft_pb(lst_a, lst_b);
			(d->c)++;
		}
		else
		{
			if (d->len > 15 && (*lst_b) && (*lst_b)->nb >= d->second_mediane
					&& ++(d->c2))
				ft_rr(lst_a, lst_b);
			else
				ft_ra(lst_a, lst_b);
		}
	}
}

void			ft_start_a_to_b(t_list **lst_a, t_list **lst_b, t_list **lst_c)
{
	t_data d;

	if ((d.len = ft_lst_len(*lst_a)) <= 3)
		return (ft_little_tri(lst_a, lst_b));
	d.mediane = ft_median(*lst_a, d.len);
	d.second_mediane = ft_second_median(*lst_a, d.len);
	d.c = 0;
	d.c2 = 0;
	ft_loop(lst_a, lst_b, &d);
	while (d.len > 15 && (d.c2)--)
		ft_rrb(lst_a, lst_b);
	if (d.c > 3 && d.len > 15)
		ft_count_sec_med(lst_b, lst_c, d.second_mediane, d.c);
	else
		ft_lst_add(lst_c, d.c);
	ft_start_a_to_b(lst_a, lst_b, lst_c);
}
