/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaystr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:26:46 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/13 15:26:47 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_displaystr(char *str, t_print_tab *tab)
{
	int to_print;
	int len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (tab->dot > 0 && tab->dot < len)
		len = tab->dot;
	to_print = len;
	if (tab->dot == 0)
		to_print = 0;
	if (tab->width < 0)
		tab->width *= -1;
	if (tab->width && !tab->minus)
		tab->printed += ft_putpad(tab->width - to_print);
	while (to_print)
	{
		tab->printed += int_putchar(*str++);
		to_print--;
	}
	if (tab->width && tab->minus)
		tab->printed += ft_putpad(tab->width - tab->printed);
}
