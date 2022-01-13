/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:01:06 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/03 10:23:18 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_is_sup_a(t_list *lst, int len, int nb)
{
	while (len)
	{
		if (lst->nb <= nb)
			return (0);
		lst = lst->next;
		len--;
	}
	return (1);
}

int	ft_is_inf_b(t_list *lst, int len, int nb)
{
	while (len)
	{
		if (lst->nb >= nb)
			return (0);
		lst = lst->next;
		len--;
	}
	return (1);
}

int	ft_is_sup_b_start(t_list *lst, int len, int nb)
{
	while (len)
	{
		if (lst->nb < nb)
			return (0);
		lst = lst->next;
		len--;
	}
	return (1);
}

int	ft_is_inf_b_start(t_list *lst, int len, int nb)
{
	while (len)
	{
		if (lst->nb > nb)
			return (0);
		lst = lst->next;
		len--;
	}
	return (1);
}
