/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:54:18 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/19 18:00:55 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_conversion(const char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_len((char)va_arg(args, int));
	if (c == 's')
		len += ft_putstr_len(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		len += ft_putnbr_len(va_arg(args, int));
	if (c == 'u')
		len += ft_u_putnbr_len(va_arg(args, unsigned int));
	if (c == 'p')
		len = len + 2 + ft_print_ptr_len(va_arg(args, void *));
	if (c == 'x' || c == 'X')
		len += ft_print_hex_len(va_arg(args, unsigned int), c);
	if (c == '%')
		len += ft_putchar_len('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_check_conversion(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

/*void	test_char()
{
	printf("===== TEST CHAR =====\n\n");
	{
		int cas1_c = ft_printf("moi --> [%c]\n", '0');
		int cas1_o = printf("ori --> [%c]\n", '0');
		if (cas1_c == cas1_o)
			ft_printf(".......... Cas 1 - OK\n");
		else
			ft_printf(".......... Cas 1 - KO\n");
	}
	ft_printf("\n");
	{
		int cas2_c = ft_printf("moi --> [%c]\n", '0' - 256);
		int cas2_o = printf("ori --> [%c]\n", '0' - 256);
		if (cas2_c == cas2_o)
			ft_printf(".......... Cas 2 - OK\n");
		else
			ft_printf(".......... Cas 2 - KO\n");
	}
	ft_printf("\n");
	{
		int cas3_c = ft_printf("moi --> [%c]\n", '0' + 256);
		int cas3_o = printf("ori --> [%c]\n", '0' + 256);
		if (cas3_c == cas3_o)
			ft_printf(".......... Cas 3 - OK\n");
		else
			ft_printf(".......... Cas 3 - KO\n");
	}
	ft_printf("\n");
	{
		int cas4_c = ft_printf("moi --> [%c %c %c]\n", '0', 0, '1');
		int cas4_o = printf("ori --> [%c %c %c]\n", '0', 0, '1');
		if (cas4_c == cas4_o)
			ft_printf(".......... Cas 4 - OK\n");
		else
			ft_printf(".......... Cas 4 - KO\n");
	}
	ft_printf("\n");
	{
		int cas5_c = ft_printf("moi --> [%c %c %c]\n", ' ', ' ', ' ');
		int cas5_o = printf("ori --> [%c %c %c]\n", ' ', ' ', ' ');
		if (cas5_c == cas5_o)
			ft_printf(".......... Cas 5 - OK\n");
		else
			ft_printf(".......... Cas 5 - KO\n");
	}
	ft_printf("\n");
	{
		int cas6_c = ft_printf("moi --> [%c %c %c]\n", '2', '1', 0);
		int cas6_o = printf("ori --> [%c %c %c]\n", '2', '1', 0);
		if (cas6_c == cas6_o)
			ft_printf(".......... Cas 6 - OK\n");
		else
			ft_printf(".......... Cas 6 - KO\n");
	}
	ft_printf("\n");
	{
		int cas7_c = ft_printf("moi --> [%c %c %c]\n", 0, '1', '2');
		int cas7_o = printf("ori --> [%c %c %c]\n", 0, '1', '2');
		if (cas7_c == cas7_o)
			ft_printf(".......... Cas 7 - OK\n");
		else
			ft_printf(".......... Cas 7 - KO\n");
	}
}

void	test_string()
{
	char	*s1 = "test de cedric";

	printf("===== TEST STRING =====\n\n");
	{
		int cas1_c = ft_printf("moi --> [%s]\n", "coucou");
		int cas1_o = printf("ori --> [%s]\n", "coucou");
		if (cas1_c == cas1_o)
			ft_printf(".......... Cas 1 - OK\n");
		else
			ft_printf(".......... Cas 1 - KO\n");
	}
	ft_printf("\n");
	{
		int cas2_c = ft_printf("moi --> [%s]\n", "");
		int cas2_o = printf("ori --> [%s]\n", "");
		if (cas2_c == cas2_o)
			ft_printf(".......... Cas 2 - OK\n");
		else
			ft_printf(".......... Cas 2 - KO\n");
	}
	ft_printf("\n");
	{
		int cas3_c = ft_printf("moi --> [%s]\n", " ");
		int cas3_o = printf("ori --> [%s]\n", " ");
		if (cas3_c == cas3_o)
			ft_printf(".......... Cas 3 - OK\n");
		else
			ft_printf(".......... Cas 3 - KO\n");
	}
	ft_printf("\n");
	{
		int cas4_c = ft_printf("moi --> [%s %s %s]\n", "ceci", "est un", s1);
		int cas4_o = printf("ori --> [%s %s %s]\n", "ceci", "est un", s1);
		if (cas4_c == cas4_o)
			ft_printf(".......... Cas 4 - OK\n");
		else
			ft_printf(".......... Cas 4 - KO\n");
	}
}

void	test_ptr()
{
	char	l = 'B';
	char	*pl = &l;

	int		m = 0;
	int		*pm = &m;

	int		n = -1;
	int		*pn = &n;

	long	o = LONG_MIN;
	long	*po = &o;

	long	p = LONG_MAX;
	long	*pp = &p;

	printf("===== TEST PTR =====\n\n");
	{
		int cas1_c = ft_printf("moi --> [%p]\n", pl);
		int cas1_o = printf("ori --> [%p]\n", pl);
		if (cas1_c == cas1_o)
			ft_printf(".......... Cas 1 - OK\n");
		else
			ft_printf(".......... Cas 1 - KO\n");
	}
	ft_printf("\n");
	{
		int cas2_c = ft_printf("moi --> [%p]\n", pm);
		int cas2_o = printf("ori --> [%p]\n", pm);
		if (cas2_c == cas2_o)
			ft_printf(".......... Cas 2 - OK\n");
		else
			ft_printf(".......... Cas 2 - KO\n");
	}
	ft_printf("\n");
	{
		int cas3_c = ft_printf("moi --> [%p]\n", pn);
		int cas3_o = printf("ori --> [%p]\n", pn);
		if (cas3_c == cas3_o)
			ft_printf(".......... Cas 3 - OK\n");
		else
			ft_printf(".......... Cas 3 - KO\n");
	}
	ft_printf("\n");
	{
		int cas4_c = ft_printf("moi --> [%p %p]\n", po, pp);
		int cas4_o = printf("ori --> [%p %p]\n", po, pp);
		if (cas4_c == cas4_o)
			ft_printf(".......... Cas 4 - OK\n");
		else
			ft_printf(".......... Cas 4 - KO\n");
	}
}

void	test_num()
{
	printf("===== TEST NUM =====\n\n");
	{
		int cas1_c = ft_printf("moi --> [%d]\n", 0);
		int cas1_o = printf("ori --> [%d]\n", 0);
		if (cas1_c == cas1_o)
			ft_printf(".......... Cas 1 - OK\n");
		else
			ft_printf(".......... Cas 1 - KO\n");
	}
	ft_printf("\n");
	{
		int cas2_c = ft_printf("moi --> [%d]\n", -12345);
		int cas2_o = printf("ori --> [%d]\n", -12345);
		if (cas2_c == cas2_o)
			ft_printf(".......... Cas 2 - OK\n");
		else
			ft_printf(".......... Cas 2 - KO\n");
	}
	ft_printf("\n");
	{
		int cas3_c = ft_printf("moi --> [%d]\n", 12345);
		int cas3_o = printf("ori --> [%d]\n", 12345);
		if (cas3_c == cas3_o)
			ft_printf(".......... Cas 3 - OK\n");
		else
			ft_printf(".......... Cas 3 - KO\n");
	}
	ft_printf("\n");
	{
		int cas4_c = ft_printf("moi --> [%d %i]\n", INT_MIN, INT_MAX);
		int cas4_o = printf("ori --> [%d %i]\n", INT_MIN, INT_MAX);
		if (cas4_c == cas4_o)
			ft_printf(".......... Cas 4 - OK\n");
		else
			ft_printf(".......... Cas 4 - KO\n");
	}
}

void	test_uns()
{
	printf("===== TEST UNS =====\n\n");
	{
		int cas1_c = ft_printf("moi --> [%u]\n", 0);
		int cas1_o = printf("ori --> [%u]\n", 0);
		if (cas1_c == cas1_o)
			ft_printf(".......... Cas 1 - OK\n");
		else
			ft_printf(".......... Cas 1 - KO\n");
	}
	ft_printf("\n");
	{
		int cas2_c = ft_printf("moi --> [%u]\n", -12345);
		int cas2_o = printf("ori --> [%u]\n", -12345);
		if (cas2_c == cas2_o)
			ft_printf(".......... Cas 2 - OK\n");
		else
			ft_printf(".......... Cas 2 - KO\n");
	}
	ft_printf("\n");
	{
		int cas3_c = ft_printf("moi --> [%u]\n", 12345);
		int cas3_o = printf("ori --> [%u]\n", 12345);
		if (cas3_c == cas3_o)
			ft_printf(".......... Cas 3 - OK\n");
		else
			ft_printf(".......... Cas 3 - KO\n");
	}
	ft_printf("\n");
	{
		int cas4_c = ft_printf("moi --> [%u %u]\n", INT_MIN, INT_MAX);
		int cas4_o = printf("ori --> [%u %u]\n", INT_MIN, INT_MAX);
		if (cas4_c == cas4_o)
			ft_printf(".......... Cas 4 - OK\n");
		else
			ft_printf(".......... Cas 4 - KO\n");
	}
}

void	test_hex()
{
	printf("===== TEST HEX =====\n\n");
	{
		int cas1_c = ft_printf("moi --> [%x]\n", 0);
		int cas1_o = printf("ori --> [%x]\n", 0);
		if (cas1_c == cas1_o)
			ft_printf(".......... Cas 1 - OK\n");
		else
			ft_printf(".......... Cas 1 - KO\n");
	}
	ft_printf("\n");
	{
		int cas2_c = ft_printf("moi --> [%x]\n", -12345);
		int cas2_o = printf("ori --> [%x]\n", -12345);
		if (cas2_c == cas2_o)
			ft_printf(".......... Cas 2 - OK\n");
		else
			ft_printf(".......... Cas 2 - KO\n");
	}
	ft_printf("\n");
	{
		int cas3_c = ft_printf("moi --> [%x]\n", 12345);
		int cas3_o = printf("ori --> [%x]\n", 12345);
		if (cas3_c == cas3_o)
			ft_printf(".......... Cas 3 - OK\n");
		else
			ft_printf(".......... Cas 3 - KO\n");
	}
	ft_printf("\n");
	{
		int cas4_c = ft_printf("moi --> [%x %X]\n", INT_MIN, INT_MAX);
		int cas4_o = printf("ori --> [%x %X]\n", INT_MIN, INT_MAX);
		if (cas4_c == cas4_o)
			ft_printf(".......... Cas 4 - OK\n");
		else
			ft_printf(".......... Cas 4 - KO\n");
	}
}

int	main(void)
{
	//test_char();
	//test_string();
	//test_ptr();
	//test_num();
	//test_uns();
	//test_hex();
	return (0);
}*/
