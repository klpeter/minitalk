/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:37:19 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/22 17:47:04 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_findsinset check if s1 char is found in set
// beg is where the first non set char is found from beg
// end is where the first non set char is foun from the end
//while t_findsinset(s1[beg] - it stops after the first char that is different
static size_t	ft_findsinset(char c, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (set[i] == c)
			j++;
		i++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	beg;
	size_t	end;

	if (s1 == 0 || set == 0)
		return (0);
	beg = 0;
	while (s1[beg] && ft_findsinset(s1[beg], set))
		beg++;
	end = ft_strlen(s1);
	while (end > beg && ft_findsinset(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - beg + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (beg < end)
	{
		str[i] = s1[beg];
		i++;
		beg++;
	}
	str[i] = 0;
	return (str);
}
