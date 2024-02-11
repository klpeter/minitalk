/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:10:34 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/11/02 15:50:27 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

// int	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// 	return (1);
// }

int	ft_putnum( long n, int base)
{
	char	*chart;
	int		count;

	chart = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnum(-n, base) + 1);
	}
	else if (n < base)
		return (ft_putchar(chart[n]));
	else
	{
		count = count + ft_putnum(n / base, base);
		return (count + ft_putnum(n % base, base));
	}
}

// int	ft_putstr(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (*s)
// 	{
// 		write(1, s, 1);
// 		s++;
// 		i++;
// 	}
// 	return (i);
// }

int	ft_printptr(void *n, int base)
{
	char	*s;

	s = "0x";
	ft_putstr(s);
	return (ft_putnum((unsigned long) n, base) + 2);
}

// int	main(void)
// {
// 	char	*i;

// 	i = "10";
// 	ft_printptr(i, 16);
// 	write (1, "\n", 1);
// 	printf("Printf calculated value: %p\n", i);
// 	return (0);
// }
