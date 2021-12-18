/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:00:29 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/18 19:08:11 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int_u(va_list ap)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(ap, unsigned int);
	count = 0;
	ft_putnbr_u(nb, &count, "0123456789");
	return (count);
}

int	ft_print_int(va_list ap)
{
	int		nb;
	int		count;

	nb = va_arg(ap, int);
	count = 0;
	ft_putnbr(nb, &count, "0123456789");
	return (count);
}

int	ft_print_char(va_list ap)
{
	unsigned char	c;

	c = (unsigned char) va_arg(ap, int);
	return (write(1, &c, 1));
}

int	ft_print_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str)
		return (write(1, str, ft_strlen(str)));
	return (write(1, "(null)", 6));
}

int	ft_print_address(va_list ap)
{
	char	*str;
	int		count;

	str = va_arg(ap, char *);
	count = 0;
	count += write(1, "0x", 2);
	if (str)
		ft_put_hex((unsigned long long)&str[0], &count, "0123456789abcdef");
	else
		count += write(1, "0", 1);
	return (count);
}
