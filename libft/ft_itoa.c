/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulker <eulker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:27:23 by eulker            #+#    #+#             */
/*   Updated: 2022/02/10 20:27:25 by eulker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_len(int n)
{
	size_t	step;

	if (n == -2147483648)
	{
		n = 147483648;
		step = 2;
	}
	if (n == 0)
		return (1);
	if (n < 0)
	{
		step = 1;
		n = n * -1;
	}
	else if (n != 147483648)
		step = 0;
	while (n)
	{
		step++;
		n /= 10;
	}
	return (step);
}

void	ft_neg_check(char *str, int *n, size_t *index)
{
	if (*n == -2147483648)
	{
		*n = 147483648;
		str[0] = '-';
		str[1] = '2';
		*index = 2;
	}
	if (*n < 0)
	{
		str[0] = '-';
		*index = 1;
		*n = *n * -1;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_count_len(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	ft_neg_check(res, &n, &i);
	res[len] = '\0';
	while (n && len-- >= i)
	{
		res[len] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}
