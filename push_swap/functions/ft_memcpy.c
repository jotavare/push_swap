/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:02:47 by jotavare          #+#    #+#             */
/*   Updated: 2022/11/22 18:02:50 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*pt_src;
	unsigned char		*pt_dest;
	size_t				i;

	pt_dest = (unsigned char *)dest;
	pt_src = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*((char *)dest + i) = *((char *)pt_src + i);
		i++;
	}
	return (pt_dest);
}
