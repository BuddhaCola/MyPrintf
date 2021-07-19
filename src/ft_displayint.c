/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:55:34 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/20 23:55:36 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_displayint(int nu, t_print_tab *tab)
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
	if (nu < 0 && (tab->zero || (tab->dot > 0)) && nu != -2147483648)
	{
		if (tab->zero)
			printed += int_putchar('-');
		tab->negative_number = 1;
		nu *= -1;
	}
	buf_int = ft_itoa(nu);
	printed += ft_widthprec(buf_int, tab);
	free(buf_int);
	return (printed);
}
