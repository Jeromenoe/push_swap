/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:50:24 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/03 10:22:44 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		ft_lst_len(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_tri_tab(int tab[], int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (++i < size)
	{
		j = i - 1;
		while (j >= 0 && tab[j] > tab[j + 1])
		{
			tmp = tab[j + 1];
			tab[j + 1] = tab[j];
			tab[j] = tmp;
			j--;
		}
	}
}

int		ft_tab_median(int tab[], int size)
{
	int i;

	size = (size % 2 == 0) ? size / 2 - 1 : size / 2;
	i = 0;
	while (i < size)
		i++;
	return (tab[i]);
}

int		ft_median(t_list *lst, int size)
{
	int i;
	int tab[size];

	i = 0;
	while (i < size)
	{
		tab[i] = lst->nb;
		lst = lst->next;
		i++;
	}
	ft_tri_tab(tab, size);
	return (ft_tab_median(tab, size));
}

int		ft_second_median(t_list *lst, int size)
{
	int i;
	int tab[size];

	i = 0;
	while (i < size)
	{
		tab[i] = lst->nb;
		lst = lst->next;
		i++;
	}
	ft_tri_tab(tab, size);
	return (ft_tab_median(tab, size / 2));
}
