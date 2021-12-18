/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:17:20 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/18 17:56:48 by kyubongchoi      ###   ########.fr       */
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

void	ft_putnbr(int nb, int *count, const char *base)
{
	char	tmp;

	if (nb == -2147483648)
		*count += write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			*count += write(1, "-", 1);
			nb = -nb;
		}
		if (nb > 9)
			ft_putnbr(nb / 10, count, base);
		tmp = base[nb % 10];
		*count += write(1, &tmp, 1);
	}
}

void	ft_putnbr_u(unsigned int nb, int *count, const char *base)
{
	int		tmp;

	if (nb > 9)
		ft_putnbr_u(nb / 10, count, base);
	tmp = base[nb % 10];
	*count += write(1, &tmp, 1);
}

void	ft_put_hex(unsigned long long nb, int *count, const char *base)
{
	int	tmp;

	if (nb > 15)
		ft_put_hex(nb / 16, count, base);
	tmp = base[nb % 16];
	*count += write(1, &tmp, 1);
}

int	ft_contains(char c, char *charset)
{
	size_t	i;

	i = 0;
	while (charset && charset[i])
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	return (0);
}
