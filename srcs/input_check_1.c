/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 03:55:46 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/23 04:41:28 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static	int	check_chars(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static	int	check_length(size_t l)
{
	if (l < 19)
		return (0);
	if (l % 19 != 0 && l % 20 != 0)
		return (0);
	return (1);
}

int	check_input(char *s)
{
	size_t	len;
	size_t	i;

	i = 0;
	if (!s[i])
		return (-1);
	len = ft_strlen(s);
	ft_putendl(ft_itoa(len));
	if (!check_chars(s) || !check_length(len))
		return (0);
	else
		return (1);
}