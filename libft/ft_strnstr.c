/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulker <eulker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:40:32 by eulker            #+#    #+#             */
/*   Updated: 2022/02/10 20:46:40 by eulker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *find, size_t len)
{
	size_t	c;

	if (*find == '\0' || h == find)
		return ((char *)h);
	c = ft_strlen(find);
	while (*h && c <= len--)
	{
		if (!(ft_strncmp((char *)h, (char *)find, c)))
			return ((char *)h);
		h++;
	}
	return (NULL);
}
