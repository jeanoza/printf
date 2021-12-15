/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:46:27 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/14 22:46:34 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int_u(va_list ap)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(ap, unsigned int);
	count = 0;
	if (ap)
		ft_putnbr_u(nb, &count);
	return (count);
}

int	ft_print_int(va_list ap)
{
	int	nb;
	int	count;

	nb = va_arg(ap, int);
	count = 0;
	if (ap)
		ft_putnbr(nb, &count);
	return (count);
}

int	ft_print_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	if (ap)
		return (write(1, &c, 1));
	return (0);
}

int	ft_print_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		return (write(1, "(null)", 6));
	if (ap)
		return (write(1, str, ft_strlen(str)));
	return (0);
}
