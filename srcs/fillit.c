/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 02:48:46 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/27 20:26:17 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

// void	ft_usage(void)
// {
// 	ft_putendl("usage: Each tetrimino has to be precisely 4 lines of 4 characters followe by a new line.\n\tA Tetrimino is a classic piece of Tetris composed f4 blocks.\n\tEach character must be either a '#' when the characters is one of the blocks of a Tetriminos or a '.' if it's empty.\n\tEach block of Tetriminos must be in contact with at least one other block on any of his 4 sides.");
// }

void	fillit(char	*s, t_tetris *tet)
{
	int	*p;
	int n;
	int i;

	i = -1;
	n = check_input(s);
	if (n == -1)
	{
		ft_putstr("error");
		return ;
	}
	else if (n == 0)
	{
		ft_putstr("error");
		return ;
	}
	p = parse_tetriminos(s);
	solve_tetrimino(p, count_tets(s), tet);
	return ;
}