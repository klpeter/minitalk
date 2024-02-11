/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:58:09 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/11/02 15:49:05 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		write(1, s, 1);
		i++;
		s++;
	}
	return (i);
}

int	print_format(char c, va_list args)
{
	int		i;
	char	s;
	char	*str;

	if (c == 'c')
	{
		s = va_arg(args, int);
		ft_putchar(s);
	}
	if (c == 's')
	{
		str = va_arg(args, char *);
		ft_putstr(str);
	}
	if (c == 'd')
	{
		i = va_arg(args, int);
		ft_putnum(i, 10);
	}
	if (c == 'p')
	{
		str = va_arg(args, char *);
		ft_printptr(str, 16);
	}
	return (0);
}
