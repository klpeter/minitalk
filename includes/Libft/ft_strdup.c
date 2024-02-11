/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:36:35 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/16 19:56:22 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// allocates memory, copies the string and points to the str.

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	i = 0;
	if (dst == 0)
		return (0);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
