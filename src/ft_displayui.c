/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:03:53 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/21 00:03:55 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digits(unsigned int nu)
{
	int		i;

	i = 0;
	while (nu >= 10)
	{
		nu /= 10;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa_ui(unsigned int nu)
{
	char	*asc;
	int		len;

	len = ft_digits(nu);
	if (!(asc = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	len--;
	while (nu >= 10)
	{
		*(asc + len) = nu % 10 + '0';
		nu /= 10;
		len--;
	}
	*(asc + len) = nu % 10 + '0';
	return (asc);
}

int			ft_displayui(unsigned int nu, t_print_tab *tab)
{
	int		printed;
	char	*buf_int;

	printed = 0;
	nu += (unsigned int)4294967295 + 1;
	if (tab->dot == 0 && nu == 0)
	{
		printed += ft_printwidth(tab, 0);
		return (printed);
	}
	if (tab->dot != -1)
		tab->zero = 0;
	buf_int = ft_itoa_ui(nu);
	printed += ft_widthprec(buf_int, tab);
	free(buf_int);
	return (printed);
}
