/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:12:55 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/01 03:35:12 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static	void	create_tetri(int *t, int *coords, int len, t_master *mst)
{
	int		i;
	int		s;

	i = -1;
	s = mst->size;
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
	int		i;

	i = -1;
	mst->size = size;
	mst->len = size * size;
	mst->area = ft_strnew(mst->len + 1);
	while (++i < mst->len)
		mst->area[i] = '.';
	if (!mst->tets || !mst->coords)
	{
		mst->tets = NULL;
		mst->coords = NULL;
		return ;
	}
}

static	int		solve(t_master *mst, int i)
{
	int x;

	if (i == mst->n)
		return (1);
	x = -1;
	while (++x < mst->len)
	{
		if (verify_location(mst->tets[i], x, mst->size, mst))
		{
			ar_tetri(mst, x, i, 1);
			if (solve(mst, i + 1) != 0)
				return (1);
			else
				ar_tetri(mst, x, i, -1);
		}
	}
	return (0);
}

void			solve_tetrimino(int *p, int n, t_master *mst)
{
	int		*coords;
	int		final;
	int		s;
	int		i;

	s = 1;
	coords = (int *)ft_memalloc(sizeof(int) * n);
	i = -1;
	while (++i < n)
		coords[i] = -1;
	final = 0;
	while (!final)
	{
		s++;
		create_tetri(p, coords, n, mst);
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
