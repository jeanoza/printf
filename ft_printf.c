/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:17:15 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/14 23:21:27 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //**TO_REMOVE
#include "ft_utils.h"
#include "ft_printf.h"

static int	ft_switch_case(char format, va_list ap)
{
	int	res;

	res = 0;
	if (format == 'c')
		return (ft_print_char(ap));
	if (format == 's')
		return (ft_print_str(ap));
	if (format == 'd' || format == 'i')
		return (ft_print_int(ap));
	if (format == 'u')
		return (ft_print_int_u(ap));
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	ap;

	i = 0;
	res = 2;
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			++i;
			if (format[i] == '%')
			{
				i += write(1, "%", 1);
				continue ;
			}
			res += ft_switch_case(format[i], ap);
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

	printf("\n***	***	test with:	%s	<===	***	***	***	***	***	*\n\n*	ft_printf:\t\t\t\tprintf:						\n\n", av[1]);
	//%c
	printf("		(return:%d)\t\t", ft_printf("*	c:%c", *(av[1])));
	printf("		(return:%d)			\n\n", printf("c:%c", *(av[1])));

	//%s
	printf("		(return:%d)\t\t", ft_printf("*	s:%s", (av[1])));
	printf("		(return:%d)			\n", printf("s:%s", (av[1])));
	printf("	(return:%d)\t\t", ft_printf("*	s:%s", (char *) (NULL)));
	printf("	(return:%d)	[NULL]		\n\n", printf("s:%s", (char *) (NULL)));

	//%d
	printf("		(return:%d)\t\t", ft_printf("*	d:%d",	atoi(av[1])));
	printf("		(return:%d)			\n", printf("d:%d",		atoi(av[1])));
	printf("	(return:%d)\t\t", ft_printf("*	d:%d",	2147483647));
	printf("	(return:%d)	[int max]	\n\n", printf("d:%d",		2147483647));
	printf("	(return:%d)\t\t", ft_printf("*	d:%d",	-2147483648));
	printf("	(return:%d)	[int min]	\n\n", printf("d:%d",		-2147483648));

	//%i
	printf("		(return:%d)\t\t", ft_printf("*	i:%i", atoi(av[1])));
	printf("		(return:%d)			\n", printf("i:%i", atoi(av[1]))); // base 10(decimal)
	printf("	(return:%d)\t\t", ft_printf("*	i:%i",	2147483647));
	printf("	(return:%d)	[int max]	\n\n", printf("i:%i",		2147483647));

	//%u
	printf("		(return:%d)\t\t", ft_printf("*	u:%u", atoi(av[1]))); // unsigned int
	printf("		(return:%d)			\n", printf("u:%u", atoi(av[1]))); // unsigned int
	printf("	(return:%d)\t\t", ft_printf("*	u:%u",	4294967295));
	printf("	(return:%d)	[unsigned max]	\n", printf("u:%u",	4294967295));
	printf("	(return:%d)\t\t", ft_printf("*	u:%u",	-1));
	printf("	(return:%d)	[input = -1]	\n\n", printf("u:%u",	-1));

	//%%:TO VERIFY RETURN VALUE...
	printf("		(return:%d)\t\t", ft_printf("*	%%:%d%%", atoi(av[1])));
	printf("		(return:%d)			\n", printf("%%:%d%%", atoi(av[1])));

	
	//=> (int) return_value = int fd(2,3,4...) + strlen(PRINTED_CHAR_NUM)

	//for %p => hex: -1 = F, -2 = E....
	printf("\nTODO:...\n");
	printf("	(return:%d)\n", printf("p	:%p", (av[1])));
	printf("	(return:%d)\n", printf("x	:%x", atoi(av[1]))); 
	printf("	(return:%d)\n", printf("X	:%X", atoi(av[1]))); 
	return (0);
}
