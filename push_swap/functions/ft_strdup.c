/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:09:18 by jotavare          #+#    #+#             */
/*   Updated: 2022/11/22 18:09:22 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

	/*
	Returns a new string that is a duplicate of the input string.
	It allocates memory for the new string and copies the contents
	of the input string into the new memory location.
	*/

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s_alloc;

	len = ft_strlen(s) + 1;
	s_alloc = (char *)malloc(len * sizeof(char));
	if (s_alloc == NULL)
		return (NULL);
	ft_memcpy(s_alloc, s, len);
	free (s_alloc);
	return (s_alloc);
}
