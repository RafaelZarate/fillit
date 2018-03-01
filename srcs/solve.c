/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:12:55 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/28 20:17:04 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	values[20][3] = {{0, 0, 0}, {1, 2, 3}, {4, 8, 12}, {1, 4, 5}, {3, 4, 5}, \
	{4, 5, 8}, {1, 2, 5}, {3, 4, 8}, {4, 5, 6}, {4, 7, 8}, {1, 2, 6}, \
	{1, 4, 8}, {2, 3, 4}, {1, 5, 9}, {1, 2, 4}, {4, 8, 9}, {1, 3, 4}, \
	{4, 5, 9}, {1, 5, 6}, {3, 4, 7}};

static	int	adjust_coords(int i, int s, int n)
{
	int	c[20][3] = {{0, 0, 0}, {1, 2, 3}, {s, (s * 2), (s * 3)}, {1, s, (s + 1)}, {(s - 1), s, (s + 1)}, \
	{s, (s + 1), (s * 2)}, {1, 2, (s + 1)}, {(s - 1), s, (s * 2)}, {s, (s + 1), (s + 2)}, {s, ((s * 2) - 1), (s * 2)}, {1, 2, (s + 2)}, \
	{1, s, (s * 2)}, {(s - 2), (s - 1), s}, {1, (s + 1), ((s * 2) + 1)}, {1, 2, s}, {s, (s * 2), ((s * 2) + 1)}, {1, (s - 1), s}, \
	{s, (s + 1), ((s * 2) + 1)}, {1, (s + 1), (s + 2)}, {(s - 1), s, ((s * 2) - 1)}};
	return (c[i][n]);
}

// TO CONTINUE TOMORROW, THIS FUNCTION WILL VERIFY
// THE SIX POSSIBLE LOCATIONS POSSIBLES
static	int	verify_location(int i, int p, int s, t_master *mst)
{
	int x;
	int r;
	int c;

	x = -1;
	r = (p + 1) + (s - ((p + 1) % s));
	c = 0;
	if (mst->area[p] == '.')
	{
		while (++x < 3)
		{
			if (i == 2 || ((i == 5 || i == 8 || i == 9 || i == 15 || i == 17) && x == 0) || ((i == 3 || i == 4 || i == 7 || i == 11 || i == 15 || i == 19) && x == 1) || ((i == 5 || i == 7 || i == 9 || i == 11 || i == 12 || i == 14 || i == 16) && x == 2))
				c++;
			else if (i == 1 || ((i == 3 || i  == 11 || i == 13 || i == 16 || i == 18) && x == 0) || ((i == 6 || i == 10 || i == 14) && (x == 0 || x == 1)))
			{
				if ((p + 1) % s == 0)
					c += 0;
				else
					c += (r > (p + (adjust_coords(i, s, x))) ? 1 : 0);
			}
			else if (((i == 4 || i == 7 || i == 19 | i == 12) && x == 0) || ((i == 12 || i == 16) && x == 1))
				c += ((r <= (p + adjust_coords(i, s, x))) ? 1 : 0);
			else if (((i == 5 || i == 8 || i == 13 || i == 17 || i == 18) && x == 1) || ((i == 3 || i == 4 || i == 6 || i == 8 || i == 10 || i == 18) && x == 2))
			{
				if ((p + 1) % s == 0)
					c += 0;
				else
					c += (((r * 2) > (p + adjust_coords(i, s, x))) ? 1 : 0);
			}
			else if ((i == 9 && x == 1) || (i == 19 && x == 2))
				c += (((r * 2) <= (p + adjust_coords(i, s, x))) ? 1 : 0);
			else if ((i == 13 || i == 15 || i == 17) && x == 2)
			{
				if ((p + 1) % s == 0)
					c += 0;
				else
					c += (((r * 3) > (p + adjust_coords(i, s, x))) ? 1 : 0);
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

static	void	create_tetri(int *t, int *coords, int len, int s, t_master *mst)
{
	int		i;

	i = -1;
	mst->tets = (int *)ft_memalloc(sizeof(int) * len);
	mst->max = (int *)ft_memalloc(sizeof(int) * len);
	mst->coords = (int *)ft_memalloc(sizeof(int) * len);
	mst->n = len;
	while (++i < len)
	{
		if (t[i])
		{
			mst->max[i] = adjust_coords(t[i], s, 2);
			mst->tets[i] = t[i];
		}
		if (coords[i] >= 0)
			mst->coords[i] = coords[i];
		else if (coords[i] == -1)
			mst->coords[i] = -1;
	}
}

static	void	create_map(int size, t_master *mst)
{
	int i;
	int i3;

	i = -1;
	mst->size = size;
	mst->len = size * size;
	mst->area = ft_strnew(mst->len + 1);
	while (++i < mst->len)
		mst->area[i] = '.';
	// ft_memset(mst->area, '.', mst->len);
	if (!mst->tets || !mst->coords)
	{
		mst->tets = NULL;
		mst->coords = NULL;
		return ;
	}
	i = -1;
	while (++i < mst->n)
	{
		if (mst->coords[i] != -1)
		{
			i3 = -1;
			mst->area[mst->coords[i]] = i + 'A';
			while (++i3 < 3)
				mst->area[mst->coords[i] + adjust_coords(mst->tets[i], size, i3)] = i + 'A';
		}
	}
 }

static	int	solve(t_master *mst, int i)
{
	if (i == mst->n)
		return (1);
	int x;
	int	a_values[3];
	
	x = -1;
	while (++x < mst->len)
	{
		a_values[0] = adjust_coords(mst->tets[i], mst->size, 0);
		a_values[1] = adjust_coords(mst->tets[i], mst->size, 1);
		a_values[2] = adjust_coords(mst->tets[i], mst->size, 2);
		if (verify_location(mst->tets[i], x, mst->size, mst))
		{
	// ft_putnbr(i);
			mst->area[x] = 65 + i;
			mst->area[x + a_values[0]] = 65 + i;
			mst->area[x + a_values[1]] = 65 + i;
			mst->area[x + a_values[2]] = 65 + i;
			if (solve(mst, ++i) != 0)
				return (1);
			// else
			// {
			// 	mst->area[x] = '.';
			// 	mst->area[x + a_values[0]] = '.';
			// 	mst->area[x + a_values[1]] = '.';
			// 	mst->area[x + a_values[2]] = '.';
			// }
		}
	}
	return (0);
}

void	solve_tetrimino(int	*p, int n, t_master *mst)
{
	int *coords;
	int final;
	int	s;

	s = 1;
	coords = (int *)ft_memalloc(sizeof(int) * n);
	int i;
	i = -1;
	while (++i < n)
		coords[i] = -1;
	final = 0;
	while (final == 0)
	{
		s++;
		create_tetri(p, coords, n, s, mst);
		create_map(s, mst);
		final = solve(mst, 0);
	}
	i = -1;
	while (++i < mst->len)
	{
		if (((i) % mst->size) == 0 && i != 0)
			ft_putchar('\n');
		ft_putchar(mst->area[i]);
	}
}