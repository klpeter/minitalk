/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:27:27 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/21 18:01:18 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static void	ft_format_check(char c, va_list *args, t_value *var, int *i)
{
	if (c == 's')
		ft_putstrl(va_arg(*args, char *), var);
	else if (c == 'd' || c == 'i')
		ft_putnum(va_arg(*args, int), var);
	else if (c == 'u')
		ft_putunnum(va_arg(*args, unsigned int), var);
	else if (c == 'x')
		ft_puthexnum(va_arg(*args, unsigned int), var, 'x');
	else if (c == 'X')
		ft_puthexnum(va_arg(*args, unsigned int), var, 'X');
	else if (c == 'p')
		ft_printptr(va_arg(*args, size_t), var);
	else if (c == 'c')
		ft_putcharl(va_arg(*args, int), var);
	else if (c == '%')
		ft_putcharl('%', var);
	else
		(*i)--;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	t_value	var;

	i = 0;
	var.len = 0;
	var.error = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_format_check(format[i], &args, &var, &i);
			i++;
		}
		else
			ft_putcharl((char)format[i++], &var);
		if (var.error < 0)
			return (-1);
	}
	va_end(args);
	return (var.len);
}

// int	main(void)
// {
// 	ft_printf("%d\n", (ft_printf("%d\n", -10)));
// 	printf("%d\n", (printf("%d\n", -10)));
// }
