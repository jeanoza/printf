/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:17:15 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/13 21:08:58 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include <stdio.h> //**TO_REMOVE

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

void	ft_putnbr(int nb, int *count)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10, count);
	ft_putchar((nb % 10) + 48);
	*count += 1;
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
	if (ap)
		return (write(1, str, ft_strlen(str)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	ap;

	i = 0;
	res = 3;
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			++i;
			if (format[i] == 'c')
				res += ft_print_char(ap);
			if (format[i] == 's')
				res += ft_print_str(ap);
			if (format[i] == 'd')
				res += ft_print_int(ap);
				
		}
		else
			write(1, &format[i], 1);
		++i;
	}
	va_end(ap);
	return (res);
}


int	main(int ac, char **av)
{
	(void)ac;

	//mine
	printf("\nft_printf:\n");
	printf("	(return:%d)\n", ft_printf("c	:%c", *(av[1])));
	printf("	(return:%d)\n", ft_printf("s	:%s", (av[1])));
	printf("	(return:%d)\n", ft_printf("d	:%d", 2147483647));

	//char....
	printf("\nprintf:\n");
	printf("	(return:%d)\n", printf("c	:%c", *(av[1])));
	printf("	(return:%d)\n", printf("s	:%s", (av[1])));
	//return min 4(when 1 char, 3 + 1), %p return 17(3 + 14(2(0x)+ 12))

	//numbers...
	// printf("sizeof	:%lu\n", sizeof atoi(av[1]));// sizeof int = 4
	printf("	(return:%d)\n", printf("d	:%d", 2147483647));
	printf("	(return:%d)\n", printf("i	:%i", atoi(av[1]))); // base 10(decimal)
	printf("	(return:%d)\n", printf("u	:%u", atoi(av[1]))); // unsigned int
	printf("	(return:%d)\n", printf("p	:%p", (av[1])));
	printf("	(return:%d)\n", printf("x	:%x", atoi(av[1]))); 
	printf("	(return:%d)\n", printf("X	:%X", atoi(av[1]))); 
	printf("	(return:%d)\n", printf("%%	:%d%%", atoi(av[1]))); 
	return (0);
}
