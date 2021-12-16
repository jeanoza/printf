/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:46:31 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/16 16:49:19 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "ft_utils.h"

int	ft_printf(const char *format, ...);
int	ft_print_int_u(va_list ap, const char *base);
int	ft_print_int(va_list ap, const char *base);
int	ft_print_char(va_list ap);
int	ft_print_str(va_list ap);
int	ft_print_address(va_list ap);

#endif
