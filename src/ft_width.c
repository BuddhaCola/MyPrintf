/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:13:28 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/18 17:13:31 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printprec(t_print_tab *tab, int numlen)
{
	int printed;

	printed = 0;
	if (tab->negative_number && !tab->zero)
	{
		printed += int_putchar('-');
	}
	if (tab->dot && tab->dot > numlen)
	{
		tab->dot -= numlen;
		while (tab->dot)
		{
			tab->dot -= int_putchar('0');
			printed++;
			if (tab->minus)
				tab->width--;
		}
	}
	return (printed);
}

int		ft_printwidth(t_print_tab *tab, int numlen)
{
	int printed;

	printed = 0;
	if (tab->width && tab->width > numlen)
	{
		if (tab->dot < numlen + tab->negative_number)
		{
			tab->width -= numlen;
		}
		tab->width -= tab->negative_number;
		if (tab->dot && tab->dot >= numlen + tab->negative_number)
			tab->width -= tab->dot;
		while (tab->width > 0)
		{
			if (tab->zero && tab->dot != 0)
				tab->width -= int_putchar('0');
			else
				tab->width -= int_putchar(' ');
			printed++;
		}
	}
	return (printed);
}
