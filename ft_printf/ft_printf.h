/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:41:44 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/19 18:01:25 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int		ft_putnbr_len(int nb);
int		ft_u_putnbr_len(unsigned int nb);
void	ft_print_ptr(unsigned long long num);
int		ft_print_ptr_len(void *ptr);
int		ft_print_hex_len(unsigned int num, char c);
int		ft_putchar_len(char c);
int		ft_putstr_len(char *str);
int		nbr_len(int n);
int		nbr_hex_len(unsigned long long n);
int		ft_printf(const char *format, ...);

#endif
