/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:17:15 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/18 19:10:13 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int_u_hex_min(va_list ap)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(ap, unsigned int);
	count = 0;
	ft_put_hex(nb, &count, "0123456789abcdef");
	return (count);
}

int	ft_print_int_u_hex_maj(va_list ap)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(ap, unsigned int);
	count = 0;
	ft_put_hex(nb, &count, "0123456789ABCDEF");
	return (count);
}

static int	ft_manage_flag(char format, va_list ap)
{
	static t_flag	flag[8] = {
		{'c', &ft_print_char},
		{'s', &ft_print_str},
		{'d', &ft_print_int},
		{'i', &ft_print_int},
		{'p', &ft_print_address},
		{'u', &ft_print_int_u},
		{'x', &ft_print_int_u_hex_min},
		{'X', &ft_print_int_u_hex_maj},
	};
	int				i;

	i = 0;
	while (i < 8)
	{
		if (flag[i].word == format)
			return (flag[i].f(ap));
		++i;
	}
	return (write(1, "%", 1));
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
			if (!ft_contains(format[++i], "\%csdixXup"))
				break ;
			res += ft_manage_flag(format[i], ap);
		}
		else
			res += write(1, &format[i], 1);
		++i;
	}
	va_end(ap);
	return (res);
}
