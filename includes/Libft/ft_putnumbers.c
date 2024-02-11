/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:46:10 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/11/23 18:26:26 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_gethexbase(char c)
{
	if (c == 'x')
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");
}

int	ft_putnum(int n, t_value *var)
{
	if (n == -2147483648)
	{
		if (ft_putstrl("-2147483648", var) == -1)
			return (ft_putcharl_error(var));
	}
	else if (n < 0)
	{
		if (ft_putcharl('-', var) == -1)
			return (ft_putcharl_error(var));
		if (ft_putnum(-n, var) == -1)
			return (ft_putcharl_error(var));
	}
	else
	{
		if (n > 9)
			if (ft_putnum(n / 10, var) == -1)
				return (ft_putcharl_error(var));
		if (ft_putcharl(n % 10 + '0', var) == -1)
			return (ft_putcharl_error(var));
	}
	return (0);
}

int	ft_printptr(size_t ptr, t_value *var)
{
	char	*base;
	int		i;
	char	str[25];

	i = 0;
	base = ft_gethexbase('x');
	if (ft_putstrl("0x", var) < 0)
		return (-1);
	if (ptr == 0 && ft_putcharl('0', var) == -1)
		ft_putcharl_error(var);
	while (ptr)
	{
		str[i++] = base[ptr % 16];
		ptr = ptr / 16;
	}
	while (i-- >= 1)
	{
		if (ft_putcharl(str[i], var) == -1)
			ft_putcharl_error(var);
	}
	return (0);
}

int	ft_puthexnum(size_t n, t_value *var, char c)
{
	char	str[25];
	char	*base;
	int		i;

	i = 0;
	base = ft_gethexbase(c);
	if (n == 0 && ft_putcharl('0', var) == -1)
		return (ft_putcharl_error(var));
	while (n)
	{
		str[i++] = base[n % 16];
		n = n / 16;
	}
	while (i-- >= 1)
	{
		if (ft_putcharl(str[i], var) == -1)
			return (ft_putcharl_error(var));
	}
	return (0);
}

int	ft_putunnum(unsigned int n, t_value *var)
{
	if (n > 9)
		if (ft_putunnum(n / 10, var) == -1)
			return (ft_putcharl_error(var));
	if (ft_putcharl(n % 10 + '0', var) == -1)
		return (ft_putcharl_error(var));
	return (0);
}
