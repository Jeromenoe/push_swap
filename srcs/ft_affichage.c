/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:50:12 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/22 11:23:59 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "list.h"

void	ft_create_tab(t_list *lst, int tab[])
{
	int i;

	i = 0;
	while (lst)
	{
		tab[i] = lst->nb;
		lst = lst->next;
		i++;
	}
}

void	ft_num(t_list *lst, int tab[], int size)
{
	int i;

	ft_create_tab(lst, tab);
	ft_tri_tab(tab, ft_lst_len(lst));
	while (lst)
	{
		i = -1;
		while (++i < size)
		{
			if (lst->nb == tab[i])
			{
				lst->num = i + 1;
				break ;
			}
		}
		lst = lst->next;
	}
}

void	ft_color(t_list **lst_a, int len_a, int size)
{
	int i;
	int j;

	if (size <= len_a)
	{
		i = -1;
		while (++i < (*lst_a)->num)
			ft_putstr("\033[36;40m-\033[037;40m");
		j = (*lst_a)->num - 1;
		while (++j < 70)
			ft_putstr(" ");
		(*lst_a) = (*lst_a)->next;
	}
	else
	{
		j = -1;
		while (++j < 70)
			ft_putstr(" ");
	}
}

void	ft_print_num(t_list *lst_a, t_list *lst_b, int len_a, int len_b)
{
	int i;
	int j;
	int size;

	i = -1;
	while (++i < 100)
		ft_putstr("\n");
	size = (len_a > len_b) ? len_a : len_b;
	while (size)
	{
		ft_color(&lst_a, len_a, size);
		if (size <= len_b)
		{
			j = -1;
			while (++j < lst_b->num)
				ft_putstr("\033[35;40m-\033[037;40m");
			lst_b = lst_b->next;
		}
		ft_putstr("\n");
		size--;
	}
}

void	ft_affichage(t_list **lst_a, t_list **lst_b)
{
	int tab_a[ft_lst_len(*lst_a)];
	int tab_b[ft_lst_len(*lst_b)];

	ft_num(*lst_a, tab_a, ft_lst_len(*lst_a));
	ft_num(*lst_b, tab_b, ft_lst_len(*lst_b));
	usleep(50000);
	ft_print_num(*lst_a, *lst_b, ft_lst_len(*lst_a), ft_lst_len(*lst_b));
}
