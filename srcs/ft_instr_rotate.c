/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:49:34 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/18 12:12:19 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_ra(t_list **lst_a, t_list **lst_b)
{
	ft_rotate(lst_a);
	if ((*lst_a)->flag == 1)
		ft_affichage(lst_a, lst_b);
	else if ((*lst_a)->file == 1)
		ft_putstr("ra\n");
	if ((*lst_a)->file != 1)
		ft_putstr_fd("ra\n", (*lst_a)->file);
}

void	ft_rb(t_list **lst_a, t_list **lst_b)
{
	ft_rotate(lst_b);
	if ((*lst_a)->flag == 1)
		ft_affichage(lst_a, lst_b);
	else if ((*lst_a)->file == 1)
		ft_putstr("rb\n");
	if ((*lst_a)->file != 1)
		ft_putstr_fd("rb\n", (*lst_a)->file);
}

void	ft_rr(t_list **lst_a, t_list **lst_b)
{
	ft_rotate(lst_a);
	ft_rotate(lst_b);
	if ((*lst_a)->flag == 1)
		ft_affichage(lst_a, lst_b);
	else if ((*lst_a)->file == 1)
		ft_putstr("rr\n");
	if ((*lst_a)->file != 1)
		ft_putstr_fd("rr\n", (*lst_a)->file);
}
