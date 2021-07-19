/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayhex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:56:58 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/21 00:56:59 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digits_x_upper(unsigned int nu)
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

char		*ft_itoa_x_upper(unsigned int nu)
{
	char	*asc;
	char	*table;
	int		len;

	len = ft_digits_x_upper(nu);
	table = "0123456789ABCDEF";
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

int			ft_displayhex_upper(unsigned int nu, t_print_tab *tab)
{
	int		printed;
	char	*buf_int;

	printed = 0;
	if (tab->dot == 0 && nu == 0)
	{
		printed += ft_printwidth(tab, 0);
		return (printed);
	}
	if (tab->dot != -1)
		tab->zero = 0;
	buf_int = ft_itoa_x_upper(nu);
	printed += ft_widthprec(buf_int, tab);
	free(buf_int);
	return (printed);
}
