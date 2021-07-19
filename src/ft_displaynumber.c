/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaynumber.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:07:10 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/21 20:07:15 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_widthprec(char *buf_int, t_print_tab *tab)
{
	int printed;
	int len;

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
