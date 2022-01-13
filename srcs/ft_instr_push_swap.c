/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:59:03 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/18 11:05:12 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_sa(t_list **lst_a, t_list **lst_b)
{
	ft_swap(*lst_a);
	if ((*lst_a)->flag == 1)
		ft_affichage(lst_a, lst_b);
	else if ((*lst_a)->file == 1)
		ft_putstr("sa\n");
	if ((*lst_a)->file != 1)
		ft_putstr_fd("sa\n", (*lst_a)->file);
}

void	ft_sb(t_list **lst_a, t_list **lst_b)
{
	ft_swap(*lst_b);
	if ((*lst_a)->flag == 1)
		ft_affichage(lst_a, lst_b);
	else if ((*lst_a)->file == 1)
		ft_putstr("sb\n");
	if ((*lst_a)->file != 1)
		ft_putstr_fd("sb\n", (*lst_a)->file);
}

void	ft_ss(t_list **lst_a, t_list **lst_b)
{
	ft_swap(*lst_a);
	ft_swap(*lst_b);
	if ((*lst_a)->flag == 1)
		ft_affichage(lst_a, lst_b);
	else if ((*lst_a)->file == 1)
		ft_putstr("ss\n");
	if ((*lst_a)->file != 1)
		ft_putstr_fd("ss\n", (*lst_a)->file);
}

void	ft_pb(t_list **lst_a, t_list **lst_b)
{
	ft_push(lst_a, lst_b);
	if ((*lst_a)->flag == 1)
		ft_affichage(lst_a, lst_b);
	else if ((*lst_a)->file == 1)
		ft_putstr("pb\n");
	if ((*lst_a)->file != 1)
		ft_putstr_fd("pb\n", (*lst_a)->file);
}

void	ft_pa(t_list **lst_a, t_list **lst_b)
{
	ft_push(lst_b, lst_a);
	if ((*lst_a)->flag == 1)
		ft_affichage(lst_a, lst_b);
	else if ((*lst_a)->file == 1)
		ft_putstr("pa\n");
	if ((*lst_a)->file != 1)
		ft_putstr_fd("pa\n", (*lst_a)->file);
}
