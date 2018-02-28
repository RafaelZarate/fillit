/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:12:55 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/28 00:03:49 by rzarate          ###   ########.fr       */
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
static	int	verify_location(int i, int p, int s)
{
	int x;
	int r;
	int c;

	x = -1;
	r = (p + 1) + (s - ((p + 1) % s));
	c = 0;
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
	if (c == 3)
		return (1);
	else
		return (0);
}

static	void	create_tetri(int *t, int *coords, int len, int s, t_tetris *tetris)
{
	int		i;

	i = -1;
	tetris->tets = (int *)ft_memalloc(sizeof(int) * len);
	tetris->max = (int *)ft_memalloc(sizeof(int) * len);
	tetris->coords = (int *)ft_memalloc(sizeof(int) * len);
	tetris->len = len;
	while (++i < len)
	{
		if (t[i])
		{
			tetris->max[i] = adjust_coords(t[i], s, 2);
			tetris->tets[i] = t[i];
		}
		if (coords[i] >= 0)
			tetris->coords[i] = coords[i];
		else if (coords[i] == -1)
			tetris->coords[i] = -1;
	}
}

static	t_map	create_map(int size, t_tetris *tets)
{
	t_map	map;
	int i;
	int i3;
	int	c;
	
	i = -1;
	c = 0;
	map = (t_map)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->area = ft_strnew(size * size);
	while (++i < (size * size))
		(map->area)[i] = '.';
	if (!tets->tets || !tets->coords)
	{
		map->tets = NULL;
		map->coords = NULL;
		return (map);
	}
	i = -1;
	while (++i < tets->len)
	{
		if (tets->coords[i] != -1)
		{
			i3 = -1;
			map->area[tets->coords[i]] = c + 65;
			while (++i3 < 3)
				map->area[tets->coords[i] + adjust_coords(tets->tets[i], size, i3)] = c + 65;
			c++;
		}
	}
	return (map);
 }

static	void	solve(t_map grid, int c, t_tetris *tetris)
{
	int x;
	int i;
	char	*map;
	int p = 0;
	int	a_values[3];
	map = grid->area;
	if (c == tetris->len)
	{
		i = -1;
		while (++i < (grid->size * grid->size))
		{
			if (i % grid->size == 0 && i != 0)
				ft_putchar('\n');
			ft_putchar(grid->area[i]);
		}
		ft_putchar('\n');
		return ;
	}
	i = -1;
	while (++i < tetris->len)
	{
		if (tetris->coords[i] == -1)
		{
			x = -1;
			a_values[0] = adjust_coords(tetris->tets[i], grid->size, 0);
			a_values[1] = adjust_coords(tetris->tets[i], grid->size, 1);
			a_values[2] = adjust_coords(tetris->tets[i], grid->size, 2);
			while (++x < ((grid->size * grid->size) - tetris->max[i]))
			{
				if (verify_location(tetris->tets[i], x, grid->size))
				{				
					if (map[x] == '.' && map[x + a_values[0]] == '.' && map[x + a_values[1]] == '.' && map[x + a_values[2]] == '.')
					{
						tetris->coords[i] = x;
						map[x] = 65 + i;
						map[x + a_values[0]] = 65 + i;
						map[x + a_values[1]] = 65 + i;
						map[x + a_values[2]] = 65 + i;
						c++;
						p++;
						break ;
					}
				}
			}
		}
	}
	if (p == tetris->len)
		solve(create_map((grid->size), tetris), c, tetris);	
	else
	{
		i = -1;
		while (++i < tetris->len)
			tetris->coords[i] = -1;
		solve(create_map((grid->size + 1), tetris), 0, tetris);
	}
}

void	solve_tetrimino(int	*p, int len, t_tetris *tets)
{
	int *c;
	int i;
	t_map grid;

	c = (int *)ft_memalloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
		c[i] = -1;
	create_tetri(p, c, len, *c, tets);
	grid = create_map(2, tets);
	solve(grid, 0, tets);
}