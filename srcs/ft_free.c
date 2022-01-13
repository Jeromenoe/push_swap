/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 10:36:33 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/03 13:48:10 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	ft_lst_c_del(t_list **lst_c)
{
	if ((*lst_c)->next)
	{
		*lst_c = (*lst_c)->next;
		free((*lst_c)->prev);
		(*lst_c)->prev = NULL;
	}
	else
	{
		free(*lst_c);
		*lst_c = NULL;
	}
}

void	ft_lst_del(t_list **lst)
{
	while (*lst)
		ft_lst_c_del(lst);
}
