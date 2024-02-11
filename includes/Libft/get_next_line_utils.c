/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:52:58 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/21 17:53:12 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//updated to check if str point to NULL
int	ft_strlengnl(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchrgnl(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

//created strcpy to return the new string instead of the lenght
static char	*ft_strcpygnl(char *s1, char *s2)
{
	char	*str;
	int		i1;
	int		i2;
	int		len;

	i1 = 0;
	i2 = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	if (s1)
	{
		while (s1[i1])
		{
			str[i1] = s1[i1];
			i1++;
		}
	}
	while (s2[i2])
		str[i1++] = s2[i2++];
	str[len - 1] = '\0';
	return (str);
}

//updated to create s1 if it does not exist
char	*ft_strjoingnl(char *s1, char *s2)
{
	char	*str;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_strcpygnl(s1, s2);
	free(s1);
	return (str);
}
