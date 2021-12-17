/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:46:27 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/17 01:28:43 kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int_u(va_list ap, const char *base)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(ap, unsigned int);
	count = 0;
	if (ft_strlen(base) == 16)
		ft_put_hex(nb, &count, base);
	else
		ft_putnbr_u(nb, &count, base);
	return (count);
}

int	ft_print_int(va_list ap, const char *base)
{
	int		nb;
	int		count;

	nb = va_arg(ap, int);
	count = 0;
	ft_putnbr(nb, &count, base);
	return (count);
}

int	ft_print_char(va_list ap)
{
	int	c;

	c = va_arg(ap, int);
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
