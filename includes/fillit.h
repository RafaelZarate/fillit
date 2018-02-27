/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 01:48:59 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/26 17:16:30 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define BUF_SIZE 4096

#include "../srcs/libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef	struct	s_tetris
{
	int	*tets;
	int	*coords;
	int	*max;
	int	len;
}				t_tetris;

typedef	struct	s_map
{
	char	*area;
	int		size;
	int		*tets;
	int		*coords;
}				*t_map;

// void			fillit(char	*s);
void	fillit(char	*s, t_tetris *tet);
int				check_input(char *s);
int			*make_tets(int	**at);
int			**parse_tets(char *s);
int			count_tets(char *s);
int			*parse_tetriminos(char *s);
// void		solve_tetrimino(int	*p, int len);
void	solve_tetrimino(int	*p, int len, t_tetris *tets);
void	set_to_dot(char c);

#endif