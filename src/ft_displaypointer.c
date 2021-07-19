/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaypointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:05:21 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/21 01:05:27 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digits_x(unsigned long long nu)
{
	int				i;

	i = 0;
	while (nu >= 16)
	{
		nu /= 16;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa_x_ptr(unsigned long long nu)
{
	char	*asc;
	char	*table;
	int		len;

	len = ft_digits_x(nu) + 2;
	table = "0123456789abcdef";
	if (!(asc = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	len--;
	while (nu >= 16)
	{
		*(asc + len) = table[nu % 16];
		nu /= 16;
		len--;
	}
	*(asc + len) = table[nu % 16];
	asc[0] = '0';
	asc[1] = 'x';
	return (asc);
}

int			ft_widthprec_ptr(char *buf_int, t_print_tab *tab)
{
	int		printed;
	int		len;

	len = ft_strlen(buf_int);
	printed = 0;
	if (tab->minus)
	{
		printed += ft_printprec(tab, len);
		printed += ft_printf(buf_int);
		printed += ft_printwidth(tab, len);
	}
	else
	{
		printed += ft_printwidth(tab, len);
		printed += ft_printprec(tab, len);
		printed += ft_printf(buf_int);
	}
	return (printed);
}

int			ft_displaypointer(unsigned long long n, t_print_tab *tab)
{
	int		printed;
	char	*buf_int;

	printed = 0;
	if (tab->dot >= 0 && n == 0)
	{
		tab->width -= 2;
		printed += ft_printwidth(tab, 0);
		printed += ft_printf("0x");
		printed += ft_printprec(tab, 0);
		return (printed);
	}
	if (tab->dot != -1)
		tab->zero = 0;
	buf_int = ft_itoa_x_ptr(n);
	printed += ft_widthprec_ptr(buf_int, tab);
	free(buf_int);
	return (printed);
}

int			ft_printpointer(unsigned long long ptr, t_print_tab *tab)
{
	int		ret;

	ret = 0;
	ret += ft_displaypointer(ptr, tab);
	return (ret);
}
