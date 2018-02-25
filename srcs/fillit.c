/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 02:48:46 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/25 08:39:38 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	fillit(char	*s)
{
	int	*p;
	int n;
	int i;

	i = -1;
	n = check_input(s);
	if (n == -1)
	{
		ft_putendl_fd("File is blank", 2);
		return ;
	}
	else if (n == 0)
	{
		ft_putendl_fd("Usage text goes here", 2);
		return ;
	}
	p = parse_tetriminos(s);
	solve_tetrimino(p, count_tets(s));
	return ;
}