/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:43:06 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/21 20:43:07 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getwidth(char *format, t_print_tab *tab, va_list a_list)
{
	if (*format == '*')
	{
		tab->width = va_arg(a_list, int);
		if (tab->width < 0)
		{
			tab->width *= -1;
			tab->minus = 1;
			tab->zero = 0;
		}
		format++;
	}
	else
		format = ft_getnumber(format, tab, a_list);
	return (format);
}
