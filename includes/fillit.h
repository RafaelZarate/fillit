/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 01:48:59 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/26 12:39:32 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define BUF_SIZE 4096

#include "../srcs/libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef	struct	s_tetri
{
	int	*tets;
	int	*locations;
	int	*max;
	int	length;
}				*t_tetris;

typedef	struct	s_map
{
	char	*area;
	int		size;
	int		*tets;
	int		*coords;
}				*t_map;

void			fillit(char	*s);
int				check_input(char *s);
int			*make_tets(int	**at);
int			**parse_tets(char *s);
int			count_tets(char *s);
int			*parse_tetriminos(char *s);
void		solve_tetrimino(int	*p, int len);
void	set_to_dot(char c);

#endif