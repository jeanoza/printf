/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:46:29 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/16 19:53:11kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <unistd.h>

size_t	ft_strlen(const char *str);
void	ft_putnbr(int nb, int *count, const char *base);
void	ft_putnbr_u(unsigned int nb, int *count, const char *base);
void	ft_put_hex(unsigned long long nb, int *count, const char *base);

#endif