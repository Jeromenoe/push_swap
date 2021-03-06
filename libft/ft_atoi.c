/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:02:56 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/03 13:31:17 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *nptr)
{
	long long	nbr;
	int			sign;

	nbr = 0;
	while ((*nptr >= 7 && *nptr <= 13) || *nptr == 32)
		nptr++;
	sign = 1;
	if (*nptr == '-')
		(sign = -1);
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (sign == 1 && ((nbr >= 922337203685477580 && *nptr >= '7') ||
			nbr >= 922337203685477581))
			return (3333333333);
		if (sign == -1 && ((nbr >= 922337203685477580 && *nptr >= '7') ||
			nbr >= 922337203685477581))
			return (3333333333);
		nbr = nbr * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * nbr);
}
