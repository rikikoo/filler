/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:12:25 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/07 19:13:39 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;
	void		*data;

	data = (void*)content;
	if ((new = (t_list*)malloc(sizeof(t_list) * content_size)) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	else
	{
		if (new != NULL)
		{
			new->content = data;
			new->content_size = content_size;
			new->next = NULL;
			return (new);
		}
		else
			return (NULL);
	}
}
