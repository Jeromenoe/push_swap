/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:58:32 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/22 10:58:27 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "list.h"

int		ft_check_line2(char **line, t_list **lst_a, t_list **lst_b)
{
	if (!ft_strcmp(*line, "ra"))
		ft_rotate(lst_a);
	else if (!ft_strcmp(*line, "rb"))
		ft_rotate(lst_b);
	else if (!ft_strcmp(*line, "rr"))
	{
		ft_rotate(lst_a);
		ft_rotate(lst_b);
	}
	else if (!ft_strcmp(*line, "rra"))
		ft_reverse_rotate(lst_a);
	else if (!ft_strcmp(*line, "rrb"))
		ft_reverse_rotate(lst_b);
	else if (!ft_strcmp(*line, "rrr"))
	{
		ft_reverse_rotate(lst_a);
		ft_reverse_rotate(lst_b);
	}
	else
	{
		free(*line);
		ft_exit(lst_a, lst_b);
	}
	return (1);
}

int		ft_check_line(char **line, t_list **lst_a, t_list **lst_b)
{
	if (!ft_strcmp(*line, "sa"))
		ft_swap(*lst_a);
	else if (!ft_strcmp(*line, "sb"))
		ft_swap(*lst_b);
	else if (!ft_strcmp(*line, "ss"))
	{
		ft_swap(*lst_a);
		ft_swap(*lst_b);
	}
	else if (!ft_strcmp(*line, "pa"))
		ft_push(lst_b, lst_a);
	else if (!ft_strcmp(*line, "pb"))
		ft_push(lst_a, lst_b);
	else
		return (ft_check_line2(line, lst_a, lst_b));
	return (1);
}

int		ft_check_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			i++;
			if (!str[i])
				return (0);
		}
		if (!str[i] || (str[i] > '9' || str[i] < '0'))
			return (0);
		while (str[i] && str[i] <= '9' && str[i] >= '0')
			i++;
		if (str[i] && str[i] != ' ')
			return (0);
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] != '\0' && (str[i] > '9' || str[i] < '0')
				&& str[i] != '-' && str[i] != '+')
			return (0);
	}
	return (1);
}

int		check(t_list *lst_a)
{
	t_list *lst;
	t_list *lst2;

	lst = lst_a;
	while (lst && lst->next)
	{
		lst2 = lst->next;
		while (lst2)
		{
			if (lst2->nb == lst->nb)
				return (0);
			lst2 = lst2->next;
		}
		lst = lst->next;
	}
	return (1);
}
