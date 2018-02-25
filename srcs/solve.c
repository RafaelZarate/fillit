/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:12:55 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/25 14:22:41 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	values[20][3] = {{0, 0, 0}, {1, 2, 3}, {4, 8, 12}, {1, 4, 5}, {3, 4, 5}, \
	{4, 5, 8}, {1, 2, 5}, {3, 4, 8}, {4, 5, 6}, {4, 7, 8}, {1, 2, 6}, \
	{1, 4, 8}, {2, 3, 4}, {1, 5, 9}, {1, 2, 4}, {4, 8, 9}, {1, 3, 4}, \
	{4, 5, 9}, {1, 5, 6}, {3, 4, 7}};

// static	t_map	create_map(int len)
// {
// 	t_map	map;
// 	int i;
// 	int i2;
	
// 	i = -1;
// 	map = (t_map)ft_memalloc(sizeof(t_map));
// 	map->size = 2 * len;
// 	map->area = (char **)ft_memalloc(sizeof(char *) * (map->size));
// 	while (++i < map->size)
// 	{
// 		i2 = -1;
// 		map->area[i] = ft_strnew((map->size));
// 		while (++i2 < map->size)
// 			map->area[i][i2] = '.';
// 	}
// 	return (map);
// }

// static	t_tetri	create_tetri(int t)
// {
// 	t_tetri tmp;
// 	int		i;
// 	int		max;

// 	i = -1;
// 	max = 0;
// 	tmp = (t_tetri)ft_memalloc(sizeof(t_tetri));
// 	tmp->tet = t;
// 	while (++i < 3)
// 		tmp->coords[i] = values[t][i];
// 	i = -1;
// 	while (++i < 3)
// 		max = ((tmp->coords[i] > max) ? tmp->coords[i] : max);
// 	tmp->max = max;
// 	return (tmp);
// }

static	void	solve(int *p, int win, int c, int i, int l, char *s)
{
	char	*s2;
	char	*s3;
	int x;
	
	printf("%d", c);
	x = -1;
	if (c == win)
	{
		printf("Daaaaaamn boiiiii");
		return ;
	}
	s2 = s;
	s3 = ft_strnew(l * l);
	s3 = ft_strcpy(s3, s2);
	while (++x < (l * l) + 1)
		s[x] = '.';
	x = -1;
	while (++x < ((l * l) - values[p[i]][2]))
	{
		if (s[x] == '.' && s[x + values[p[i]][0] + (l - 2)] == '.' && s[x + values[p[i]][1] + (l - 2)] == '.' && s[x + values[p[i]][2] + (l - 2)] == '.')
		{
			s[x] = '#';
			s[x + values[p[i]][0] + (l - 2)] = '#';
			s[x + values[p[i]][1] + (l - 2)] = '#';
			s[x + values[p[i]][2] + (l - 2)] = '#';
			solve(p, win, ++c, ++i, l, s);
		}
	}
	solve(p, win, c, 0, ++l, s);
}

void	solve_tetrimino(int	*p, int len)
{
	char	*str = "....";
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
	solve(p, len, 0, 0, 2, str);
}