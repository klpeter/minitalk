/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:15:53 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/11 19:50:47 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize < 1)
	{
		while (src[i])
		{
			i++;
		}
		return (i);
	}
	while (i < dstsize -1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
	{
		dst[i] = '\0';
	}
	while (src[i])
	{
		i++;
	}
	return (i);
}
// the function has to return the lenght it tried to copy/copied
