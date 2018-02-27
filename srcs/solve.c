/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:12:55 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/26 17:27:13 by rzarate          ###   ########.fr       */
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

	i = -1;
	map = grid->area;
	if (c == tetris->len)
	{
		i = -1;
		while (++i < grid->size * grid->size)
		{
			if (i % grid->size == 0 && i != 0)
				ft_putchar('\n');
		ft_putchar(grid->area[i]);
		}
		return ;
	}
	while (++i < tetris->len)
	{
		if (tetris->coords[i] == -1)
		{
			x = -1;
			while (++x < ((grid->size * grid->size) - tetris->max[i]))
			{
				if (map[x] == '.' && map[x + adjust_coords(tetris->tets[i], grid->size, 0)] == '.' && map[x + adjust_coords(tetris->tets[i], grid->size, 1)] == '.' && map[x + adjust_coords(tetris->tets[i], grid->size, 2)] == '.')
				{
					tetris->coords[i] = x;
					create_tetri(tetris->tets, tetris->coords, tetris->len, grid->size, tetris);
					solve(create_map(grid->size, tetris), ++c, tetris);			
				}
			}
		}
	}
	solve(create_map(++grid->size, tetris), 0, tetris);
}

void	solve_tetrimino(int	*p, int len, t_tetris *tets)
{
	int c[3] = {-1, -1, -1};
	t_map grid;

	create_tetri(p, c, len, 2, tets);
	grid = create_map(5, tets);
	solve(grid, 0, tets);
}