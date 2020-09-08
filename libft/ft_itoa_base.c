/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikikytt <rikikytt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 21:26:10 by rikikytt          #+#    #+#             */
/*   Updated: 2020/09/07 19:13:13 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		count_length(unsigned long long n, int base)
{
	int		len;

	len = 0;
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(unsigned long long n, int base, int upper)
{
	int					len;
	unsigned long long	tmp;
	char				*str;
	char				*nb;

	len = count_length(n, base);
	tmp = n;
	nb = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	str[len] = '\0';
	len--;
	while (n > 0 && len >= 0)
	{
		tmp = n % base;
		n = n / base;
		str[len] = (upper > 0 && tmp >= 10) ? nb[tmp] - 32 : nb[tmp];
		len--;
	}
	return (str);
}
