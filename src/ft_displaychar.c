/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaychar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:43:09 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/17 22:43:14 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_displaychar(int c, t_print_tab *tab)
{
	int		printed;
	char	put;

	put = ' ';
	if (tab->zero)
		put = '0';
	printed = 0;
	if (tab->width && !tab->minus)
		while (printed + 1 < tab->width)
			printed += int_putchar(put);
	printed += int_putchar(c);
	if (tab->width && tab->minus)
		while (printed < tab->width)
			printed += int_putchar(' ');
	return (printed);
}
