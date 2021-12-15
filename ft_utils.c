/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:46:40 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/14 22:46:40 by kyubongchoi      ###   ########.fr       */
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_u(unsigned int nb, int *count)
{
	if (nb > 9)
		ft_putnbr_u(nb / 10, count);
	ft_putchar((nb % 10) + 48);
	*count += 1;
}

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
			*count += 1;
		}
		if (nb > 9)
			ft_putnbr(nb / 10, count);
		ft_putchar((nb % 10) + 48);
		*count += 1;
	}
}
