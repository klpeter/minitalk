/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:59:16 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/22 16:06:51 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//with recursive function this is much easier and quicker

void	ft_putnbr_fd(int n, int fd)
{
	char	number;

	number = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		number = n % 10 + '0';
		write(fd, &number, 1);
	}
	else
	{
		number = n % 10 + '0';
		write(fd, &number, 1);
	}
}
