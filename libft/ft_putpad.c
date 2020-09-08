/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikikytt <rikikytt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:42:51 by rikikytt          #+#    #+#             */
/*   Updated: 2020/09/07 19:14:44 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putpad(int len, char c)
{
	if (len < 1)
		return ;
	while (len--)
		ft_putchar(c);
}
