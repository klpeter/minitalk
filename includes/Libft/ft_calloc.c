/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:22:51 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/22 15:47:36 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*allocates specified amount of memory and then sets them to 0
to handle overflows mem / count != count - because the overflow amended the
number of the size */

void	*ft_calloc(size_t count, size_t size)
{
	size_t	mem;
	void	*ptr;

	mem = count * size;
	if (count != 0 && mem / count != size)
		return (0);
	ptr = malloc(sizeof(char) * mem);
	if (ptr == 0)
		return (0);
	else
	{
		ft_bzero(ptr, mem);
	}
	return (ptr);
}
