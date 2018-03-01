/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 05:24:40 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/01 05:38:12 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

static	int	set_tet_1(int *p, int i)
{
	if (i < 4 && p[i + 4] && p[i + 8] && p[i + 12])
		return (2);
	else if (i < 7 && p[i + 4] && p[i + 8] && p[i + 9])
		return (15);
	else if (i < 7 && p[i + 4] && p[i + 5] && p[i + 9])
		return (17);
	else if (i < 7 && p[i + 1] && p[i + 5] && p[i + 9])
		return (13);
	else if (i < 8 && p[i + 4] && p[i + 5] && p[i + 8])
		return (5);
	else if (i < 8 && p[i + 3] && p[i + 4] && p[i + 8])
		return (7);
	else if (i < 8 && p[i + 1] && p[i + 4] && p[i + 8])
		return (11);
	else if (i < 8 && p[i + 4] && p[i + 7] && p[i + 8])
		return (9);
	else if (i < 9 && p[i + 3] && p[i + 4] && p[i + 7])
		return (19);
	else if (i < 10 && p[i + 4] && p[i + 5] && p[i + 6])
		return (8);
	else if (i < 10 && p[i + 1] && p[i + 2] && p[i + 6])
		return (10);
	else if (i < 10 && p[i + 1] && p[i + 5] && p[i + 6])
		return (18);
	return (0);
}

static	int	set_tet_2(int *p, int i)
{
	if (i < 11 && p[i + 3] && p[i + 4] && p[i + 5])
		return (4);
	else if (i < 11 && p[i + 1] && p[i + 4] && p[i + 5])
		return (3);
	else if (i < 11 && p[i + 1] && p[i + 2] && p[i + 5])
		return (6);
	else if (i < 12 && p[i + 2] && p[i + 3] && p[i + 4])
		return (12);
	else if (i < 12 && p[i + 1] && p[i + 3] && p[i + 4])
		return (16);
	else if (i < 12 && p[i + 1] && p[i + 2] && p[i + 4])
		return (14);
	else if (i < 13 && p[i + 1] && p[i + 2] && p[i + 3])
		return (1);
	return (0);
}

static	int	*create_tets(int **aa, int n)
{
	int	*a;
	int x;
	int y;
	int i;

	i = 0;
	x = -1;
	a = (int *)ft_memalloc(sizeof(int) * n);
	while (++x < n)
	{
		y = -1;
		while (++y < 16)
		{
			if (aa[x][y] == 1)
			{
				if (!(a[i] = set_tet_1(aa[x], y)))
					a[i] = set_tet_2(aa[x], y);
				if (!a[i])
					return (NULL);
				i++;
				break ;
			}
		}
	}
	return (a);
}

int			**parse_tets(char *s)
{
	int		**a;
	int		i;
	int		i2;
	int		x;
	int		n;

	n = count_tets(s);
	a = (int **)ft_memalloc(sizeof(int *) * n);
	i = -1;
	x = -1;
	while (++i < n)
	{
		a[i] = (int *)ft_memalloc(sizeof(int) * 16);
		i2 = 0;
		while (++x < (20 * (i + 1) + i))
		{
			if (s[x] != '\n')
			{
				a[i][i2] = ((s[x] == '.') ? 0 : 1);
				i2++;
			}
		}
	}
	return (a);
}

int			*parse_tetriminos(char *s)
{
	int	*r;
	int	n;

	n = count_tets(s);
	r = create_tets(parse_tets(s), n);
	if (!r)
	{
		print_error(6);
		return (0);
	}
	return (r);
}
