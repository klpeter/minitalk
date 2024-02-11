/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:13:32 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/22 18:12:17 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//creates a new list while applying f function on each element
//all created nodes are initially the last one so new->next == NULL, but 
//ft_lstadd_back is puting them to the last place of the list, and sets the
//previous last nodes memory to the new last node

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*result;

	new = NULL;
	result = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (new == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = NULL;
		if (result == NULL)
			result = new;
		else
			ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
