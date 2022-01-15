/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 02:57:03 by dabey             #+#    #+#             */
/*   Updated: 2019/11/27 19:07:06 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
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
