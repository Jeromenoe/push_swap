/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:59:32 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/18 12:12:39 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_rra(t_list **lst_a, t_list **lst_b)
{
	ft_reverse_rotate(lst_a);
	if ((*lst_a)->flag == 1)
		ft_affichage(lst_a, lst_b);
	else if ((*lst_a)->file == 1)
		ft_putstr("rra\n");
	if ((*lst_a)->file != 1)
		ft_putstr_fd("rra\n", (*lst_a)->file);
}

void	ft_rrb(t_list **lst_a, t_list **lst_b)
{
	ft_reverse_rotate(lst_b);
	if ((*lst_a)->flag == 1)
		ft_affichage(lst_a, lst_b);
	else if ((*lst_a)->file == 1)
		ft_putstr("rrb\n");
	if ((*lst_a)->file != 1)
		ft_putstr_fd("rrb\n", (*lst_a)->file);
}

void	ft_rrr(t_list **lst_a, t_list **lst_b)
{
	ft_reverse_rotate(lst_a);
	ft_reverse_rotate(lst_b);
	if ((*lst_a)->flag == 1)
		ft_affichage(lst_a, lst_b);
	else if ((*lst_a)->file == 1)
		ft_putstr("rrr\n");
	if ((*lst_a)->file != 1)
		ft_putstr_fd("rrr\n", (*lst_a)->file);
}
