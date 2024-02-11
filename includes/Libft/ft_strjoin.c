/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:58:54 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/11 19:48:15 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//creates a new string where it unifies s1 and s2 and terminates with \0.

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i1;
	size_t	i2;

	str = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	i1 = 0;
	i2 = 0;
	if (str == 0)
		return (0);
	while (s1[i1])
	{
		str[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		str[i1 + i2] = s2[i2];
		i2++;
	}
	str[i1 + i2] = '\0';
	return (str);
}
