/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 03:40:09 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/01 04:16:55 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static	int	check_ix1(int i, int x, int p, int s)
{
	int r;

	r = (p + 1) + (s - ((p + 1) % s));
	if (i == 2 || ((i == 5 || i == 8 || i == 9 || i == 15 || i == 17) && x == 0)
	|| ((i == 3 || i == 4 || i == 7 || i == 11 || i == 15 || i == 19) && x == 1)
	|| ((i == 5 || i == 7 || i == 9 || i == 11 || i == 12 || i == 14 || i == 16)
	&& x == 2))
		return (1);
	else if (i == 1 || ((i == 3 || i == 11 || i == 13 || i == 16 || i == 18) &&
	x == 0) || ((i == 6 || i == 10 || i == 14) && (x == 0 || x == 1)))
	{
		if ((p + 1) % s == 0)
			return (0);
		return (r > (p + (adjust_coords(i, s, x))) ? 1 : 0);
	}
	else if (((i == 4 || i == 7 || i == 19 | i == 12) && x == 0) ||
	((i == 12 || i == 16) && x == 1))
	{
		if ((p + 1) % s == 0)
			return (((r - s) <= (p + adjust_coords(i, s, x))) ? 1 : 0);
		else
			return ((r <= (p + adjust_coords(i, s, x))) ? 1 : 0);
	}
	return (0);
}

static	int	check_ix2(int i, int x, int p, int s)
{
	int r;

	r = (p + 1) + (s - ((p + 1) % s));
	if (((i == 5 || i == 8 || i == 13 || i == 17 || i == 18) && x == 1) ||
	((i == 3 || i == 4 || i == 6 || i == 8 || i == 10 || i == 18) && x == 2))
	{
		if ((p + 1) % s == 0)
			return (0);
		return (((r + s) > (p + adjust_coords(i, s, x))) ? 1 : 0);
	}
	else if ((i == 9 && x == 1) || (i == 19 && x == 2))
	{
		if ((p + 1) % s == 0)
			return (((r + s) >= (p + adjust_coords(i, s, x))) ? 1 : 0);
		else
			return (((r + s) <= (p + adjust_coords(i, s, x))) ? 1 : 0);
	}
	else if ((i == 13 || i == 15 || i == 17) && x == 2)
	{
		if ((p + 1) % s == 0)
			return (0);
		return (((r + (2 * s)) > (p + adjust_coords(i, s, x))) ? 1 : 0);
	}
	return (0);
}

int			verify_location(int i, int p, int s, t_master *mst)
{
	int		x;
	int		c;

	x = -1;
	c = 0;
	if (mst->area[p] == '.')
	{
		while (++x < 3)
		{
			c += check_ix1(i, x, p, s);
			c += check_ix2(i, x, p, s);
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
