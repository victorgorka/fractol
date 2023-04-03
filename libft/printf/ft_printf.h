/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:56:47 by vde-prad          #+#    #+#             */
/*   Updated: 2022/07/12 13:53:34 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//*******************STANDARD LIBRARIES*************************************
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
//************************FUNCTIONS*****************************************
unsigned int	ft_putchar(const unsigned char c);
size_t			ft_strlen(const char *s);
unsigned int	ft_putstr(char *s);
int				ft_printf(char const *str, ...);
unsigned int	ft_puthex(const char *t, unsigned long long n);
unsigned int	ft_putnbr(int n);
unsigned int	ft_putnbru(unsigned long n);
#endif
