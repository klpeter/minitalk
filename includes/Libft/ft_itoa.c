/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:23:43 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/18 19:53:48 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//count the numbers to allocate enough memory, then converting the int to string

static size_t	ft_countnumber(int num)
{
	size_t	len;

	len = 0;
	if (num == -2147483648)
		return (11);
	if (num == 0)
		return (1);
	if (num < 0)
		len = len + 1;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}
//moving to unsigned int to handle int_min after changing it to +

char	*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	no;

	len = ft_countnumber(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	no = n;
	if (s == NULL)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		no = -n;
	}
	if (no == 0)
		s[0] = '0';
	s[len] = '\0';
	while (no)
	{
		s[len - 1] = (no % 10) + '0';
		no = no / 10;
		len--;
	}
	return (s);
}

// int	main(void)
// {
// 	int	test;

// 	test = -2147483648;
// 	printf("%s", ft_itoa(test));
// }
