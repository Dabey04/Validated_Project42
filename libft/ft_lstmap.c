/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:31:07 by dabey             #+#    #+#             */
/*   Updated: 2019/11/27 19:32:21 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstclear1(t_list **lst, void (*del)(void*))
{
	t_list *head;
	t_list *element;

	if (lst == NULL)
		return ;
	head = *lst;
	while (head)
	{
		element = head->next;
		del(head->content);
		free(head);
		head = element;
	}
	*lst = NULL;
}

static t_list	*ft_lstnew1(void *content)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list			*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del)
(void *))
{
	t_list *new_list;

	if (!lst || !f)
		return (NULL);
	if (!(new_list = ft_lstnew1(f(lst->content))))
	{
		ft_lstclear1(&new_list, del);
		return (NULL);
	}
	new_list->next = ft_lstmap(lst->next, f, del);
	return (new_list);
}
