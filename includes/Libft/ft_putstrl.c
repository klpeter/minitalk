/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:01:34 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/11/23 18:26:38 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstrl(char *args, t_value *var)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		if (write(1, "(null)", 6) == -1)
			return (ft_putcharl_error(var));
		var->len = var->len + 6;
	}
	else
	{
		while (args[i])
		{
			if (ft_putcharl(args[i], var) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}
