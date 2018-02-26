/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 11:56:33 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/26 09:39:23 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		count_tets(char *s)
{
	int i;
	int c;

	i = ft_strlen(s) - 1;
	c = 1;
	while (--i > 0)
	{
		if (s[i] == '\n' && s[i - 1] == '\n')
			c++;
	}
	return (c);
}

void	set_to_dot(char c)
{
	c = '.';
}

// int	access_values(int *ar, int i)
// {

// }