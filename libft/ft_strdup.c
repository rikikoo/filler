/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:27:21 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/07 19:15:15 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*s2;

	length = 0;
	while (s1[length] != '\0')
	{
		length++;
	}
	s2 = (char*)malloc(sizeof(char) * (length + 1));
	if (s2 == NULL)
		return (0);
	else
	{
		length = 0;
		while (s1[length] != '\0')
		{
			s2[length] = s1[length];
			length++;
		}
		s2[length] = '\0';
		return (s2);
	}
}
