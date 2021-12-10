/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:17:15 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/10 17:44:09 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include <stdio.h>

int	ft_print_char(va_list ap, int	*index)
{
	char	c;

	c = va_arg(ap, int);
	if (ap)
	{
		write(1, &c, 1);
		*index += 1;
	}
	return (1);
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
			if (format[i + 1] == 'c')
				res += ft_print_char(ap, &i);
		}
		else
			write(1, &format[i], 1);
		++i;
	}
	va_end(ap);
	return (0);
}



int	main(int ac, char **av)
{
	(void)ac;

	//mine
	printf("\nft_printf:\n");
	ft_printf("c test	:%c\n", *(av[1]));

	//char....
	printf("\nprintf:\n");
	printf("	(return:%d)\n", printf("c	:%c", *(av[1])));
	printf("	(return:%d)\n", printf("s	:%s", (av[1])));
	printf("	(return:%d)\n", printf("p	:%p", (av[1])));
	//return min 4(when 1 char, 3 + 1), %p return 17(3 + 14(2(0x)+ 12))

	//numbers...
	// printf("sizeof	:%lu\n", sizeof atoi(av[1]));// sizeof int = 4
	printf("	(return:%d)\n", printf("d	:%d", atoi(av[1])));
	printf("	(return:%d)\n", printf("i	:%i", atoi(av[1]))); // base 10(decimal)
	printf("	(return:%d)\n", printf("u	:%u", atoi(av[1]))); // unsigned int
	printf("	(return:%d)\n", printf("x	:%x", atoi(av[1]))); 
	printf("	(return:%d)\n", printf("X	:%X", atoi(av[1]))); 
	printf("	(return:%d)\n", printf("%%	:%d%%", atoi(av[1]))); 
	return (0);
}
