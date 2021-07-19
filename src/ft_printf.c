/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:30:42 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/22 15:12:22 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_parsesymbols(char *format, t_print_tab *tab, va_list a_list)
{
	if ((*format >= 9 && *format <= 13) || *format == ' ')
	{
		if (*(format + 1) != ' ')
			tab->printed += int_putchar(' ');
		format++;
	}
	else if (*format == '0' && !tab->minus)
	{
		tab->zero = 1;
		format++;
	}
	else if (ft_isdigit(*format) || *format == '*' || *format == '.')
	{
		if (!(*(format + 1)))
			return (++format);
		format = ft_getwidth(format, tab, a_list);
	}
	else if (*format == '-')
	{
		tab->minus = 1;
		tab->zero = 0;
		format++;
	}
	return (*(format + 1) ? format++ : format);
}

char			*ft_parseconversion(char *format, t_print_tab *tab,
									va_list a_list)
{
	if (*format == 's')
		ft_displaystr(va_arg(a_list, char *), tab);
	else if (*format == 'c' || *format == '%')
	{
		if (*format == '%')
			tab->printed += ft_displaychar('%', tab);
		if (*format == 'c')
			tab->printed += ft_displaychar(va_arg(a_list, int), tab);
	}
	else if (ft_strchr("diuxX", *format))
	{
		if (*format == 'x')
			tab->printed += ft_displayhex_lower(va_arg(a_list, unsigned int),
												tab);
		else if (*format == 'X')
			tab->printed += ft_displayhex_upper(va_arg(a_list, unsigned int),
												tab);
		else if (*format == 'u')
			tab->printed += ft_displayui(va_arg(a_list, unsigned int), tab);
		else
			tab->printed += ft_displayint(va_arg(a_list, int), tab);
	}
	else if (*format == 'p')
		tab->printed += ft_printpointer(va_arg(a_list, size_t), tab);
	return (format);
}

char			*ft_parcer(char *format, va_list a_list, t_print_tab *tab)
{
	while (*format && ((ft_strchr("-*. ", *format) || ft_isdigit(*format))))
		format = ft_parsesymbols(format, tab, a_list);
	if (*format && ft_strchr("cspdiuxX%", *format))
		format = ft_parseconversion(format, tab, a_list);
	if (*format == '\0')
		return (format);
	return (++format);
}

int				ft_formattreat(char *format, va_list a_list)
{
	t_print_tab	tab;
	int			ret;

	ret = 0;
	if (!format)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1))
		{
			ft_tabinit(&tab);
			format = ft_parcer(format++ + 1, a_list, &tab);
			ret += tab.printed;
		}
		else if (*format != '%')
			ret += int_putchar(*format++);
		else
			return (-1);
	}
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list a_list;
	int		ret;

	ret = 0;
	va_start(a_list, format);
	ret += ft_formattreat((char *)format, a_list);
	va_end(a_list);
	return (ret);
}
