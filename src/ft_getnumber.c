/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:20:30 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/21 20:20:32 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_getnumber(char *format, t_print_tab *tab, va_list a_list)
{
	if (*format == '.' && *(format + 1))
	{
		tab->dot = 0;
		format++;
		if (*format == '*')
		{
			tab->dot = va_arg(a_list, int);
			if (tab->dot < 0)
				tab->dot = -1;
			format++;
		}
		else
			while (ft_isdigit(*format))
			{
				tab->dot *= 10;
				tab->dot += (*format - '0');
				format++;
			}
	}
	while (*format && *format >= '0' && *format <= '9')
	{
		tab->width *= 10;
		tab->width += (*format++ - '0');
	}
	return (format);
}
