/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:00:26 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/11/23 18:26:15 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putcharl(char c, t_value *var)
{
	if (write(1, &c, 1) == -1)
	{
		var->error = -1;
		return (-1);
	}
	else
		var->len++;
	return (0);
}

int	ft_putcharl_error(t_value *var)
{
	var->error = -1;
	return (-1);
}
