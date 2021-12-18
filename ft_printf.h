/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:17:34 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/18 19:08:45 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "ft_utils.h"

int	ft_printf(const char *format, ...);
int	ft_print_int_u(va_list ap);
int	ft_print_int_u_hex_min(va_list ap);
int	ft_print_int_u_hex_maj(va_list ap);
int	ft_print_int(va_list ap);
int	ft_print_char(va_list ap);
int	ft_print_str(va_list ap);
int	ft_print_address(va_list ap);

typedef struct s_flag {
	char	word;
	int		(*f)(va_list);
}	t_flag;

#endif
