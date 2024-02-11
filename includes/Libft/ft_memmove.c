/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:45:25 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/22 15:59:00 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//memmove copies the source to a buffer before moving it to destination so it
//is safe to use when the destination and source overlap
//if malloc cannot allocate memory, then we return NULL 
// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	char	*tmp;

// 	tmp = (char *)malloc(len);
// 	if (tmp == NULL)
// 		return (NULL);
// 	ft_memcpy(tmp, src, len);
// 	ft_memcpy(dst, tmp, len);
// 	free(tmp);
// 	return (dst);
// but malloc is not allowed in this function.

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	cpy;

	if (dst == 0 && src == 0)
		return (0);
	if (dst > src)
	{
		cpy = len;
		while (cpy > 0)
		{
			cpy--;
			((char *)dst)[cpy] = ((char *)src)[cpy];
		}
	}
	else
	{
		cpy = 0;
		while (cpy < len)
		{
			((char *)dst)[cpy] = ((char *)src)[cpy];
			cpy++;
		}
	}
	return (dst);
}
// if dst overlaps src then it copies in reverse order avoiding to overwriting 
// data before it is copied