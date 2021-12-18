/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:00:56 by kychoi            #+#    #+#             */
/*   Updated: 2021/12/18 17:56:53 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <unistd.h>

size_t	ft_strlen(const char *str);
void	ft_putnbr(int nb, int *count, const char *base);
void	ft_putnbr_u(unsigned int nb, int *count, const char *base);
void	ft_put_hex(unsigned long long nb, int *count, const char *base);
int		ft_contains(char c, char *charset);

#endif