/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:50:35 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/03 10:37:43 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int		ft_is_tri_a(t_list *lst, int len)
{
	while (lst->next && len)
	{
		if (lst->nb > lst->next->nb)
			return (0);
		lst = lst->next;
		len--;
	}
	return (1);
}

int		ft_is_tri_b(t_list *lst, int len)
{
	while (lst->next && len)
	{
		if (lst->nb < lst->next->nb)
			return (0);
		lst = lst->next;
		len--;
	}
	return (1);
}
