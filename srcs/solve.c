/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:12:55 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/26 22:47:20 by rzarate          ###   ########.fr       */
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

static	int	check_valid_pos(int *a_values, int s, int x)
{
	if (((a_values[0] == s || a_values[0] == (2 * s) || a_values[0] == (3 * s)) \
		|| ((a_values[0] < 4 && a_values[0] < s && ((a_values[0] + x) >= ((x + 1) + (s - ((x + 1) % s))))) \
		|| (a_values[0] > 3 && a_values[0] < s && ((a_values[0] + x) >= ((x + 1) + (s - ((x + 1) % s))))) \
		|| (((a_values[0] > s) && (a_values[0] > s * 2)) && ((a_values[0] + x) >= ((x + 1) + (s - ((x + 1) % s))))) \
		|| ((a_values[0] > (2 * s) && a_values[0] < (3 * s)) && ((a_values[0] + x) >= ((x + 1) + (s - ((x + 1) % s))))))) \
		&& ((a_values[1] == s || a_values[1] == (2 * s) || a_values[1] == (3 * s)) \
		||(a_values[1] < 4 && a_values[1] < s && ((a_values[1] + x) >= ((x + 1) + (s - ((x + 1) % s))))) \
		|| (a_values[1] > 3 && a_values[1] < s && ((a_values[1] + x) >= ((x + 1) + (s - ((x + 1) % s))))) \
		|| (((a_values[1] > s) && (a_values[1] > s * 2)) && ((a_values[1] + x) >= ((x + 1) + (s - ((x + 1) % s))))) \
		|| ((a_values[1] > (2 * s) && a_values[1] < (3 * s)) && ((a_values[1] + x) >= ((x + 1) + (s - ((x + 1) % s)))))) \
		&& ((a_values[2] == s || a_values[2] == (2 * s) || a_values[2] == (3 * s)) \
		|| (a_values[2] < 4 && a_values[2] < s && ((a_values[2] + x) >= ((x + 1) + (s - ((x + 1) % s))))) \
		|| (a_values[2] > 3 && a_values[2] < s && ((a_values[2] + x) >= ((x + 1) + (s - ((x + 1) % s))))) \
		|| (((a_values[2] > s) && (a_values[2] > s * 2)) && ((a_values[2] + x) >= ((x + 1) + (s - ((x + 1) % s))))) \
		|| ((a_values[2] > (2 * s) && a_values[2] < (3 * s)) && ((a_values[2] + x) >= ((x + 1) + s - ((x + 1) % s))))))
				return (1);
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

// static	void	solve(t_map grid, int c, t_tetris *tetris)
// {
// 	int x;
// 	int i;
// 	char	*map;
// 	ft_putstr("C ");ft_putnbr(c);
// 	ft_putchar('\t');
// 	ft_putstr("t->l ");ft_putnbr(tetris->len);
// 	ft_putchar('\t');
// 	ft_putstr("m->size ");ft_putnbr(grid->size);
// 	ft_putchar('\n');
// 	int p = 0;
// 	int	a_values[3];
// 	map = grid->area;
// 	i = -1;
// 	while (++i < (grid->size * grid->size))
// 	{
// 		if (i % grid->size == 0 && i != 0)
// 			ft_putchar('\n');
// 		ft_putchar(grid->area[i]);
// 	}
// 	ft_putchar('\n');ft_putchar('\n');
// 	if (c == tetris->len)
// 	{
// 		i = -1;
// 		while (++i < (grid->size * grid->size))
// 		{
// 			if (i % grid->size == 0 && i != 0)
// 				ft_putchar('\n');
// 			ft_putchar(grid->area[i]);
// 		}
// 		return ;
// 	}
// 	i = -1;
// 	while (++i < tetris->len)
// 	{
// 		if (tetris->coords[i] == -1)
// 		{
// 			x = -1;
// 			a_values[0] = adjust_coords(tetris->tets[i], grid->size, 0);
// 			a_values[1] = adjust_coords(tetris->tets[i], grid->size, 1);
// 			a_values[2] = adjust_coords(tetris->tets[i], grid->size, 2);
// 			while (++x < ((grid->size * grid->size) - tetris->max[i]))
// 			{

// 					if (map[x] == '.' && map[x + a_values[0]] == '.' && map[x + a_values[1]] == '.' && map[x + a_values[2]] == '.')
// 					{
// 						tetris->coords[i] = x;
// 						map[x] = 65 + c;
// 						map[x + a_values[0]] = 65 + c;
// 						map[x + a_values[1]] = 65 + c;
// 						map[x + a_values[2]] = 65 + c;
// 						c++;
// 						p++;
// 						create_tetri(tetris->tets, tetris->coords, tetris->len, grid->size, tetris);
// 						break ;
// 					}
// 			}
// 		}
// 	}
// 	if (p > 0)
// 		solve(create_map((grid->size), tetris), c, tetris);	
// 	else
// 		solve(create_map((grid->size + 1), tetris), c, tetris);
// }

static	void	solve(t_map grid, int c, t_tetris *tetris)
{
	int x;
	int i;
	char	*map;
	ft_putstr("C ");ft_putnbr(c);
	ft_putchar('\t');
	ft_putstr("t->l ");ft_putnbr(tetris->len);
	ft_putchar('\t');
	ft_putstr("m->size ");ft_putnbr(grid->size);
	ft_putchar('\n');
	int p = 0;
	int	a_values[3];
	map = grid->area;
	i = -1;
	while (++i < (grid->size * grid->size))
	{
		if (i % grid->size == 0 && i != 0)
			ft_putchar('\n');
		ft_putchar(grid->area[i]);
	}
	ft_putchar('\n');ft_putchar('\n');
	if (c == tetris->len)
	{
		i = -1;
		while (++i < (grid->size * grid->size))
		{
			if (i % grid->size == 0 && i != 0)
				ft_putchar('\n');
			ft_putchar(grid->area[i]);
		}
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
				if (check_valid_pos(a_values, grid->size, x))
				{				
					if (map[x] == '.' && map[x + a_values[0]] == '.' && map[x + a_values[1]] == '.' && map[x + a_values[2]] == '.')
					{
						tetris->coords[i] = x;
						map[x] = 65 + c;
						map[x + a_values[0]] = 65 + c;
						map[x + a_values[1]] = 65 + c;
						map[x + a_values[2]] = 65 + c;
						c++;
						p++;
						create_tetri(tetris->tets, tetris->coords, tetris->len, grid->size, tetris);
						break ;
					}
				}
			}
		}
	}
	if (p > 0)
		solve(create_map((grid->size), tetris), c, tetris);	
	else
		solve(create_map((grid->size + 1), tetris), c, tetris);
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