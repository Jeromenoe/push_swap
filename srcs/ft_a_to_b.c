/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:53:48 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/03 10:24:03 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	ft_loop(t_list **lst_a, t_list **lst_b, t_data *d)
{
	int i;

	i = -1;
	while (++i < d->len)
	{
		if (i < d->len - 1 && ft_is_sup_a(*lst_a, d->len - i, d->mediane) == 0
				&& ft_is_sup_a(*lst_a, d->len - i + 1, d->mediane) == 1)
			ft_sa(lst_a, lst_b);
		else if ((*lst_a)->nb <= d->mediane)
		{
			ft_pb(lst_a, lst_b);
			(d->c)++;
		}
		else
		{
			if (ft_is_sup_a(*lst_a, d->len - i, d->mediane) == 0)
				ft_ra(lst_a, lst_b);
			else
				(d->c2)++;
		}
	}
}

void		ft_a_to_b(t_list **lst_a, t_list **lst_b, t_list **lst_c, int len)
{
	t_data	d;
	int		i;

	d.len = len;
	d.mediane = ft_median(*lst_a, d.len);
	if (d.len <= 3)
	{
		ft_tri_inf3_a(lst_a, lst_b, d.len);
		return (ft_b_to_a(lst_a, lst_b, lst_c));
	}
	d.c = 0;
	d.c2 = 0;
	ft_loop(lst_a, lst_b, &d);
	i = -1;
	while (++i < d.len - d.c - d.c2)
		ft_rra(lst_a, lst_b);
	ft_lst_add(lst_c, d.c);
	ft_a_to_b(lst_a, lst_b, lst_c, d.len - d.c);
}
