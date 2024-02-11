/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:55:45 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/16 16:25:08 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//locates the first occurance of c in s string and gives back the rest of the 
//string.

char	*ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (0);
}
//need to return the pointer to the found character with casting it.