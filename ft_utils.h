/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:46:29 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/14 22:46:30 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <unistd.h>

void	ft_putchar(char c);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int nb, int *count);
void	ft_putnbr_u(unsigned int nb, int *count);

#endif