/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:45:07 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/11 16:58:39 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//I have to put "\n" instead '\n' otherwise it won't work and gives warning

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	char	*str;
// 	int		df;

// 	str = "Hello world";
// 	df = 1;
// 	ft_putendl_fd(str, df);
// 	return (0);
// }
