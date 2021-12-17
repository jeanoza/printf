/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:17:15 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/17 01:40:24 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //**TO_REMOVE
#include "ft_utils.h"
#include "ft_printf.h"

static int	ft_switch_case(char format, va_list ap)
{
	if (ap)
	{
		if (format == '%')
			return (write(1, "%", 1));
		else if (format == 'c')
			return (ft_print_char(ap));
		else if (format == 's')
			return (ft_print_str(ap));
		else if (format == 'd' || format == 'i')
			return (ft_print_int(ap, "0123456789"));
		else if (format == 'x')
			return (ft_print_int_u(ap, "0123456789abcdef"));
		else if (format == 'X')
			return (ft_print_int_u(ap, "0123456789ABCDEF"));
		else if (format == 'u')
			return (ft_print_int_u(ap, "0123456789"));
		else if (format == 'p')
			return (ft_print_address(ap));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	ap;

	i = 0;
	res = 0;
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '\%')
		{
			if (format[++i])
				res += ft_switch_case(format[i], ap);
		}
		else
			res += write(1, &format[i], 1);
		++i;
	}
	va_end(ap);
	return (res);
}
