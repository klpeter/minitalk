/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:48:11 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/22 17:54:02 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//copies s to substring from the start character to the len and terminates
//with 0, returns the copied substring.

static size_t	ft_memlen(char const *s, unsigned int start, size_t len)
{
	if (s == 0)
		return (0);
	if (start > (unsigned int)ft_strlen(s))
		len = 0;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	return (len);
}
//if len is bigger than strlen(s) - start, then it updates the len value for
//the difference, which will be the max possible lenght

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	len = ft_memlen(s, start, len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

//it will copy only if i reaches the vaue of start, to make sure the
//copy happenes only from start