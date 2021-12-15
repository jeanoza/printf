/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:46:40 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/15 22:28:07 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		++i;
	return (i);
}

void	ft_putnbr_u(unsigned int nb, int *count)
{
	int	tmp;

	tmp = (nb % 10) + 48;
	if (nb > 9)
		ft_putnbr_u(nb / 10, count);
	*count += write(1, &tmp, 1);
}

void	ft_putnbr(int nb, int *count, const char *base)
{
	char	tmp;
	size_t	base_len;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
	}
	else
	{
		base_len = ft_strlen(base);
		if (nb < 0)
		{
			*count += write(1, "-", 1);
			nb = -nb;
		}
		if (nb > base_len - 1)
			ft_putnbr(nb / base_len, count, base);
		tmp = base[nb % base_len];
		*count += write(1, &tmp, 1);
	}
}
#include<stdio.h> //**TO_REMOVE

void	ft_putnbr_hex(int nb, int *count, const char *base)
{
	char		tmp;
	size_t		base_len;

	base_len = ft_strlen(base);
	if (nb < 0 && (-nb) < 2147483647)
	{
		// if (-nb * base_len < 2147483647)
		// 	return ;
		*count += write(1, &base[base_len - 1], 1);
		ft_putnbr_hex(nb * base_len, count, base);
	}
	else
	{
		if (nb > base_len - 1)
			ft_putnbr_hex(nb / base_len, count, base);
		tmp = base[nb % base_len];
		*count += write(1, &tmp, 1);
	}
}
