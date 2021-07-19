/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:55:02 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/13 16:55:46 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_tabinit(t_print_tab *tab)
{
	tab->printed = 0;
	tab->dot = -1;
	tab->precision = 0;
	tab->width = 0;
	tab->minus = 0;
	tab->zero = 0;
	tab->negative_number = 0;
}
