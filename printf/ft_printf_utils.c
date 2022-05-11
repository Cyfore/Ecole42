/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulker <eulker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:02:08 by eulker            #+#    #+#             */
/*   Updated: 2022/02/24 23:02:09 by eulker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int		i;
	char	*s;

	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	s = ft_itoa(n);
	i = ft_printstr(s);
	free(s);
	return (i);
}
