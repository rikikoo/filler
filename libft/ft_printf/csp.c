/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:08:41 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/07 19:27:59 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_char(t_specs *specs, va_list argp)
{
	char	c;

	c = va_arg(argp, int);
	if (specs->width < 2)
	{
		ft_putchar(c);
		return (1);
	}
	else
	{
		if (specs->minus)
			ft_putchar(c);
		ft_putpad(specs->width - 1, specs->zero ? '0' : ' ');
		if (!specs->minus)
			ft_putchar(c);
		return (specs->width);
	}
}

int		print_string(t_specs *specs, char *str, int len)
{
	if (specs->width > len)
	{
		if (specs->minus)
			ft_putnstr(str, len);
		ft_putpad(specs->width - len, specs->zero ? '0' : ' ');
		if (!specs->minus)
			ft_putnstr(str, len);
		return (specs->width);
	}
	ft_putnstr(str, len);
	return (len);
}

int		prep_string(t_specs *specs, va_list argp)
{
	int		len;
	char	*str;

	str = va_arg(argp, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (specs->precision >= 0 && specs->precision < len)
		return (print_string(specs, str, specs->precision));
	else
		return (print_string(specs, str, len));
}

int		print_pointer(t_specs *specs, va_list argp)
{
	unsigned long long	ptr;
	int					len;
	char				*str;
	char				*tmp;

	if (!(ptr = (unsigned long long)(va_arg(argp, void *))))
		ptr = 0;
	tmp = ft_itoa_base(ptr, 16, 0);
	if (ptr == 0 && specs->precision == 0)
		str = ft_strdup("0x");
	else
		str = ft_strjoin("0x", tmp);
	free(tmp);
	len = ft_strlen(str);
	if (len >= specs->width)
	{
		ft_putstr(str);
		free(str);
		return (len);
	}
	specs->minus ? ft_putstr(str) : ft_putpad(specs->width - len, ' ');
	!specs->minus ? ft_putstr(str) : ft_putpad(specs->width - len, ' ');
	free(str);
	return (specs->width);
}
