/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:32:58 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/22 16:12:51 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//it returns the lenght of string it tried to create= dest len + src len
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;

	d = 0;
	s = 0;
	while (d < dstsize && dst[d])
	{
		d++;
	}
	while (src[s] && (d + s + 1) < dstsize)
	{
		dst[d + s] = src[s];
		s++;
	}
	if (d < dstsize)
	{
		dst[d + s] = '\0';
	}
	return (d + ft_strlen((char *)src));
}
