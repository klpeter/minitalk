/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:10:55 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/20 14:36:27 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//creates a new node,that points to the content as content and NULL as next node

t_list	*ft_lstnew(void *content)
{
	t_list	*lnklst;

	lnklst = (t_list *)malloc(sizeof(*lnklst));
	if (lnklst == NULL)
		return (NULL);
	lnklst -> content = content;
	lnklst -> next = NULL;
	return (lnklst);
}
