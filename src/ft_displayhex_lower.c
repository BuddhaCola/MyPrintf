/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayhex_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:55:16 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/21 00:55:19 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digits_x(unsigned int nu)
{
	int		i;

	i = 0;
	while (nu >= 16)
	{
		nu /= 16;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa_x(unsigned int nu)
{
	char	*asc;
	char	*table;
	int		len;

	len = ft_digits_x(nu);
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
	return (asc);
}

int			ft_displayhex_lower(unsigned int n, t_print_tab *tab)
{
	int		printed;
	char	*buf_int;

	printed = 0;
	if (tab->dot == 0 && n == 0)
	{
		printed += ft_printwidth(tab, 0);
		return (printed);
	}
	if (tab->dot != -1)
		tab->zero = 0;
	buf_int = ft_itoa_x(n);
	printed += ft_widthprec(buf_int, tab);
	free(buf_int);
	return (printed);
}
