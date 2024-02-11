/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:09:19 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/22 16:39:02 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//locates the last occurence of c in s string, and gives back pointer to to the
//located char in s

char	*ft_strrchr(const char *s, char c)
{
	int	i;

	i = ft_strlen((char *)s);
	if (c == 0)
	{
		return ((char *)s + i);
	}
	while (i >= 0)
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (0);
}
