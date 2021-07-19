/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:33:14 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/21 22:38:43 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../ft_libft/libft.h"
# include <stdarg.h>

typedef	struct
{
	int		precision;
	int		printed;
	int		width;
	int		minus;
	int		zero;
	int		dot;
	int		star;
	int		negative_number;
}			t_print_tab;

int			ft_printf(const char *format, ...);
int			int_putchar(int c);
int			int_putchar(int c);
char		*ft_getnumber(char *format, t_print_tab *tab, va_list a_list);
char		*ft_getwidth(char *format, t_print_tab *tab, va_list a_list);
void		ft_tabinit(t_print_tab *tab);
int			ft_putpad(int toprint);
int			ft_displaychar(int c, t_print_tab *tab);
void		ft_displaystr(char *str, t_print_tab *tab);
int			ft_displayint(int nu, t_print_tab *tab);
int			ft_displayhex_lower(unsigned int n, t_print_tab *tab);
int			ft_displayhex_upper(unsigned int n, t_print_tab *tab);
int			ft_displayui(unsigned int nu, t_print_tab *tab);
int			ft_printpointer(unsigned long long ptr, t_print_tab *tab);
int			ft_printprec(t_print_tab *tab, int numlen);
int			ft_printwidth(t_print_tab *tab, int numlen);
int			ft_widthprec(char *buf_int, t_print_tab *tab);
char		*ft_itoa_x(unsigned int nu);

#endif
