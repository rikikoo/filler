/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:06:17 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/07 19:13:35 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
** {
**	t_list		*tmp;
**	t_list		*new;
**
**	tmp = f(lst);
**	if (!tmp)
**		return (NULL);
**	new = tmp;
**	while (lst->next != NULL)
**	{
**		lst = lst->next;
**		new->next = f(lst);
**		if (new->next == NULL)
**			return (NULL);
**		new = new->next;
**	}
**	return (tmp);
** }
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*new;
	t_list		*cpy;

	cpy = f(lst);
	new = ft_lstnew(cpy->content, cpy->content_size);
	if (!new)
		return (NULL);
	tmp = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		cpy = f(lst);
		new->next = ft_lstnew(cpy->content, cpy->content_size);
		if (new->next == NULL)
		{
			free(new);
			return (NULL);
		}
		new = new->next;
	}
	return (tmp);
}
