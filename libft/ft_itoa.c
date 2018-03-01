/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:13:58 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/22 01:53:36 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		n_digits(int n)
{
	int	r;

	r = 0;
	if (n < 0)
	{
		r++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		r++;
		n /= 10;
	}
	return (r);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = n_digits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = ft_strnew(len);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		i = 1;
		s[0] = '-';
	}
	while (--len >= i)
	{
		s[len] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}
