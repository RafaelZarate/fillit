/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 11:56:33 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/04 01:14:22 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int			count_tets(char *s)
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

void		ar_tetri(t_master *mst, int x, int i, int v)
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

static	int	adjust_coords1(int i, int s, int n, int c[20][3])
{
	c[5][0] = s;
	c[5][1] = s + 1;
	c[5][2] = s * 2;
	c[6][0] = 1;
	c[6][1] = 2;
	c[6][2] = s + 1;
	c[7][0] = s - 1;
	c[7][1] = s;
	c[7][2] = s * 2;
	c[8][0] = s;
	c[8][1] = s + 1;
	c[8][2] = s + 2;
	c[9][0] = s;
	c[9][1] = (s * 2) - 1;
	c[9][2] = s * 2;
	c[10][0] = 1;
	c[10][1] = 2;
	c[10][2] = (s + 2);
	c[11][0] = 1;
	c[11][1] = s;
	c[11][2] = (s * 2);
	c[12][0] = s - 2;
	c[12][1] = s - 1;
	c[12][2] = s;
	return (c[i][n]);
}

static	int	adjust_coords2(int i, int s, int n, int c[20][3])
{
	c[13][0] = 1;
	c[13][1] = s + 1;
	c[13][2] = (s * 2) + 1;
	c[14][0] = 1;
	c[14][1] = 2;
	c[14][2] = s;
	c[15][0] = s;
	c[15][1] = s * 2;
	c[15][2] = (s * 2) + 1;
	c[16][0] = 1;
	c[16][1] = s - 1;
	c[16][2] = s;
	c[17][0] = s;
	c[17][1] = s + 1;
	c[17][2] = (s * 2) + 1;
	c[18][0] = 1;
	c[18][1] = s + 1;
	c[18][2] = s + 2;
	c[19][0] = s - 1;
	c[19][1] = s;
	c[19][2] = (s * 2) - 1;
	return (c[i][n]);
}

int			adjust_coords(int i, int s, int n)
{
	int	c[20][3];

	if (i < 5)
	{
		c[0][0] = 0;
		c[0][1] = 0;
		c[0][2] = 0;
		c[1][0] = 1;
		c[1][1] = 2;
		c[1][2] = 3;
		c[2][0] = s;
		c[2][1] = (s * 2);
		c[2][2] = (s * 3);
		c[3][0] = 1;
		c[3][1] = s;
		c[3][2] = (s + 1);
		c[4][0] = s - 1;
		c[4][1] = s;
		c[4][2] = s + 1;
		return (c[i][n]);
	}
	else if (i >= 5 && i < 13)
		return (adjust_coords1(i, s, n, c));
	else
		return (adjust_coords2(i, s, n, c));
}
