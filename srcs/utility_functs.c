/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 11:56:33 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/01 04:42:21 by rzarate          ###   ########.fr       */
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

void	ar_tetri(t_master *mst, int x, int i, int v)
{
	int a_values[3];

	a_values[0] = adjust_coords(mst->tets[i], mst->size, 0);
	a_values[1] = adjust_coords(mst->tets[i], mst->size, 1);
	a_values[2] = adjust_coords(mst->tets[i], mst->size, 2);
	if (v == 1)
	{
		mst->area[x] = 65 + i;
		mst->area[x + a_values[0]] = 65 + i;
		mst->area[x + a_values[1]] = 65 + i;
		mst->area[x + a_values[2]] = 65 + i;
	}
	else if (v == -1)
	{
		mst->area[x] = '.';
		mst->area[x + a_values[0]] = '.';
		mst->area[x + a_values[1]] = '.';
		mst->area[x + a_values[2]] = '.';
	}
}

int		adjust_coords(int i, int s, int n)
{
	int	c[20][3] = {{0, 0, 0}, {1, 2, 3}, {s, (s * 2), (s * 3)},\
	{1, s, (s + 1)}, {(s - 1), s, (s + 1)}, {s, (s + 1), (s * 2)},\
	{1, 2, (s + 1)}, {(s - 1), s, (s * 2)}, {s, (s + 1), (s + 2)},\
	{s, ((s * 2) - 1), (s * 2)}, {1, 2, (s + 2)}, {1, s, (s * 2)},\
	{(s - 2), (s - 1), s}, {1, (s + 1), ((s * 2) + 1)},\
	{1, 2, s}, {s, (s * 2), ((s * 2) + 1)}, {1, (s - 1), s},\
	{s, (s + 1), ((s * 2) + 1)}, {1, (s + 1), (s + 2)},\
	{(s - 1), s, ((s * 2) - 1)}};
	return (c[i][n]);
}
