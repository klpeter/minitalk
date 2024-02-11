/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:45:34 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/22 16:36:42 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//looks for the first occurenece of needle in haystack with limited search
//lenght len
//if needle is 0  haystack is returned, if needle is not in haystack return 0,
// needle == 0 would mean that the pointer points to invaid memory, while if
//I want to tell the string is empty, I should say needle[0] == '\0'.
//if found pointer to the first character of first occurence of needle returned

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (needle[n] == '\0')
		return ((char *)haystack);
	while (haystack[h] && h < len)
	{
		if (haystack[h] == needle[n])
		{
			while (haystack[h + n] == needle[n] && h + n < len)
			{
				if (needle[n + 1] == '\0')
					return ((char *)haystack + h);
				n++;
			}
			n = 0;
		}
		h++;
	}
	return (0);
}
