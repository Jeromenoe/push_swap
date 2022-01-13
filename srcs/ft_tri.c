/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:00:40 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/03 10:22:53 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	ft_tri(t_list **lst_a, t_list **lst_b)
{
	t_list *lst_c;

	lst_c = NULL;
	if ((*lst_a)->flag == 1)
		ft_affichage(lst_a, lst_b);
	ft_first_start_a_to_b(lst_a, lst_b, &lst_c);
	if (*lst_b)
		ft_b_to_a(lst_a, lst_b, &lst_c);
}
