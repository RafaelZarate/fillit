/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 11:56:33 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/01 03:31:54 by rzarate          ###   ########.fr       */
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

int		verify_location(int i, int p, int s, t_master *mst)
{
	int		x;
	int		r;
	int		c;

	x = -1;
	r = (p + 1) + (s - ((p + 1) % s));
	c = 0;
	if (mst->area[p] == '.')
	{
		while (++x < 3)
		{
			if (i == 2 || ((i == 5 || i == 8 || i == 9 || i == 15 || i == 17)
			&& x == 0) || ((i == 3 || i == 4 || i == 7 || i == 11 || i == 15
			|| i == 19) && x == 1) || ((i == 5 || i == 7 || i == 9 || i == 11
			|| i == 12 || i == 14 || i == 16) && x == 2))
				c++;
			else if (i == 1 || ((i == 3 || i == 11 || i == 13 || i == 16
			|| i == 18) && x == 0) || ((i == 6 || i == 10 || i == 14) &&
			(x == 0 || x == 1)))
			{
				if ((p + 1) % s == 0)
					break ;
				c += (r > (p + (adjust_coords(i, s, x))) ? 1 : 0);
			}
			else if (((i == 4 || i == 7 || i == 19 | i == 12) && x == 0) ||
			((i == 12 || i == 16) && x == 1))
			{
				if ((p + 1) % s == 0)
					c += (((r - s) <= (p + adjust_coords(i, s, x))) ? 1 : 0);
				else
					c += ((r <= (p + adjust_coords(i, s, x))) ? 1 : 0);
			}
			else if (((i == 5 || i == 8 || i == 13 || i == 17 || i == 18) &&
			x == 1) || ((i == 3 || i == 4 || i == 6 || i == 8 || i == 10
			|| i == 18) && x == 2))
			{
				if ((p + 1) % s == 0)
					break ;
				c += (((r + s) > (p + adjust_coords(i, s, x))) ? 1 : 0);
			}
			else if ((i == 9 && x == 1) || (i == 19 && x == 2))
			{
				if ((p + 1) % s == 0)
					c += (((r + s) >= (p + adjust_coords(i, s, x))) ? 1 : 0);
				else
					c += (((r + s) <= (p + adjust_coords(i, s, x))) ? 1 : 0);
			}
			else if ((i == 13 || i == 15 || i == 17) && x == 2)
			{
				if ((p + 1) % s == 0)
					break ;
				c += (((r + (2 * s)) > (p + adjust_coords(i, s, x))) ? 1 : 0);
			}
		}
	}
	if (c == 3)
	{
		if (mst->area[p + (adjust_coords(i, s, 0))] == '.' && \
			mst->area[p + (adjust_coords(i, s, 1))] == '.' && \
			mst->area[p + (adjust_coords(i, s, 2))] == '.')
			return (1);
	}
	return (0);
}
