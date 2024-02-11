/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:42:26 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/22 18:00:24 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//deletes and frees the given node and all nods after it.
//need the temp to store the next node's address
// while (lst && *lst) valid pointer and valid node  
//temp saved the address of the next node  so it is not lost while the current
//one is beind deleted.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (lst && *lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
