/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:50:12 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/10/22 16:04:31 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
//memset returns a void (generic) pointer to allow a more use of function
//casting the generic pointer b to a char pointer
//it starts from the end if thee string len-1 len--

{
	char	*cb;

	cb = (char *)b;
	while (len > 0)
	{
		cb[len - 1] = c;
		len--;
	}
	return (b);
}

// int	main(void)

// {
// 	char	str[50] = "Really need to use void pointers?";
// 	ft_memset(str + 12, '?', 6);
// 	printf("%s\n", str);
// 	return 0;
// }
