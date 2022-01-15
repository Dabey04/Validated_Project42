/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:00:39 by dabey             #+#    #+#             */
/*   Updated: 2019/11/26 19:42:37 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *head;

	if (!(*alst))
		*alst = new;
	head = *alst;
	while (head->next != NULL)
		head = head->next;
	head->next = new;
	new->next = NULL;
}
