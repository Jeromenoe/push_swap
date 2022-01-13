/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:13:52 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/22 11:15:53 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "list.h"

void	ft_usage(void)
{
	ft_putstr("./push_swap [-v] <random values> \n -v : 60 values max\n");
	exit(0);
}

int		ft_opt(int ac, char **av, t_opt *opt)
{
	int i;

	i = ac;
	opt->v = (!ft_strcmp(av[1], "-v")) ? 1 : 0;
	opt->beg = opt->v;
	opt->f = 1;
	if ((!ft_strcmp(av[1], "-f")) && ac >= 3)
	{
		if ((opt->f = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
			ft_exit(NULL, NULL);
		opt->beg = 2;
	}
	return (i);
}

void	ft_fill_list(int ac, char **av, t_list **lst_a, t_opt *opt)
{
	int i;
	int j;

	i = ft_opt(ac, av, opt);
	while (--i > opt->beg)
	{
		if (!ft_check_str(av[i]))
			ft_exit_a(lst_a);
		j = ft_strlen(av[i]) - 1;
		while (j >= 0)
		{
			while (j >= 0 && av[i][j] == ' ')
				j--;
			while (j >= 0 && av[i][j] >= '0' && av[i][j] <= '9')
				j--;
			if (av[i][j] == '-' || av[i][j] == '+')
				j--;
			j++;
			ft_lst_add(lst_a, ft_atoi(&av[i][j]));
			(*lst_a)->flag = opt->v;
			(*lst_a)->file = opt->f;
			j--;
		}
	}
}

int		ft_already_tri(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_opt	opt;

	if (ac == 1)
		return (0);
	lst_b = NULL;
	lst_a = NULL;
	ft_fill_list(ac, av, &lst_a, &opt);
	if (check(lst_a) == 0)
		ft_exit_a(&lst_a);
	if (ft_lst_len(lst_a) > 60 && opt.v == 1)
		ft_usage();
	if (!ft_already_tri(lst_a))
		ft_tri(&lst_a, &lst_b);
	ft_lst_del(&lst_a);
	ft_lst_del(&lst_b);
	return (0);
}
