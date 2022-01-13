/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:26:08 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/22 14:53:52 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "list.h"

int		ft_opt(int ac, char **av, t_opt *opt)
{
	int i;

	i = ac;
	opt->f = 0;
	opt->beg = 0;
	opt->color = 0;
	if (!ft_strcmp(av[1], "-f") && ac >= 4)
	{
		if ((opt->f = open(av[2], O_RDONLY)) == -1)
			ft_exit(NULL, NULL);
		opt->beg = 2;
	}
	if (!ft_strcmp(av[1], "-c") && ac >= 3)
	{
		opt->beg = 1;
		opt->color = 1;
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
			j--;
		}
	}
}

void	ft_ok(t_opt opt)
{
	if (opt.color == 1)
		ft_putstr("\033[32;40m");
	ft_putstr("OK\n");
	if (opt.color == 1)
		ft_putstr("\033[037;40m");
}

void	ft_ko(t_opt opt)
{
	if (opt.color == 1)
		ft_putstr("\033[31;40m");
	ft_putstr("KO\n");
	if (opt.color == 1)
		ft_putstr("\033[037;40m");
}

int		main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	*line;
	int		res;
	t_opt	opt;

	if (ac == 1)
		return (0);
	lst_b = NULL;
	lst_a = NULL;
	ft_fill_list(ac, av, &lst_a, &opt);
	if (check(lst_a) == 0)
		ft_exit_a(&lst_a);
	while (get_next_line(opt.f, &line) > 0
			&& ft_check_line(&line, &lst_a, &lst_b))
		free(line);
	res = ft_check_list(lst_a, lst_b);
	if (res == 1)
		ft_ok(opt);
	else if (res == 0)
		ft_ko(opt);
	ft_lst_del(&lst_a);
	ft_lst_del(&lst_b);
	free(line);
	return (0);
}
