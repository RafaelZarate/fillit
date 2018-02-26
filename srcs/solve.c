/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:12:55 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/26 12:39:43 by rzarate          ###   ########.fr       */
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

static	t_map	create_map(int size, int *tets, int *coords)
{
	t_map	map;
	int i;
	int	i2;
	int i3;
	int	a_values[3];
	
	i = -1;
	i2 = 0;
	map = (t_map)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->area = ft_strnew(size * size);
	while (++i < (size * size))
		(map->area)[i] = '.';
	if (!tets || !coords)
	{
		map->tets = NULL;
		map->coords = NULL;
		return (map);
	}
	i = -1;
	while (++i < (size * size))
	{
		if (i == coords[i2])
		{
			i3 = -1;
			while (++i3 < 3)
				a_values[i3] = adjust_coords(tets[i2], size, i3);
			i3 = -1;
			(map->area)[i] = i2 + 65;
			while (++i3 < 3)
				(map->area)[i + a_values[i3]] = i2 + 65;
			i2++;
		}
	}
	return (map);
}

//Im gonna check first if create_map is working properly
// static	void	solve(t_map grid, int win, int c, int *tetris)
// {
// 	int x;
// 	int i;
// 	char	*map;

// 	if (c == win)
// 	{
// 		printf("Daaaaaamn boiiiii");
// 		return ;
// 	}
// 	map = grid->area;
// 	x = -1;
// 	i = 0;
// 	while (++x < ((grid->size * grid->size) - )
// 	{
		
// 	}
// 	solve(create_map(++(grid->size), ), win, c, 0, ++l, s);
// }

static	t_tetris	create_tetri(int *t)
{
	t_tetris tetris;
	int		i;
	int		max;

	i = -1;
	max = 0;
	tetris = (t_tetris)ft_memalloc(sizeof(t_tetris));
	tetris->tet = t;
	while (++i < 3)
		tmp->coords[i] = values[t][i];
	i = -1;
	while (++i < 3)
		max = ((tmp->coords[i] > max) ? tmp->coords[i] : max);
	tmp->max = max;
	return (tmp);
}

void	solve_tetrimino(int	*p, int len)
{
	t_map grid;
	int arr[4] = {3, 2, 2, 3};
	int pos[4] = {0, 2, 3, 8};
	// t_map	grid;
	// t_tetri	tetri[len];
	// int i;

	// i = -1;
	// grid = create_map(len);
	// while (++i < len)
	// {
	// 	tetri[i] = create_tetri(p[i]);
	// 	printf("tet: %d, %d, %d, %d,max: %d\n", tetri[i]->tet, tetri[i]->coords[0], tetri[i]->coords[1], tetri[i]->coords[2], tetri[i]->max);
	// }
	grid = create_map(4, arr, pos);
	len++;
	p++;
	printf("%s", grid->area);
}