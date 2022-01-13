/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 10:59:58 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/22 14:42:20 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	ft_exit(t_list **lst_a, t_list **lst_b)
{
	if (lst_a)
		ft_lst_del(lst_a);
	if (lst_b)
		ft_lst_del(lst_b);
	ft_putstr("Error\n");
	exit(0);
}

void	ft_exit_a(t_list **lst_a)
{
	if (lst_a)
		ft_lst_del(lst_a);
	ft_putstr("Error\n");
	exit(0);
}

void	ft_exit_b(t_list **lst_b)
{
	if (lst_b)
		ft_lst_del(lst_b);
	ft_putstr("Error\n");
	exit(0);
}
