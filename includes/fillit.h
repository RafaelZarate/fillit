/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 01:48:59 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/01 04:24:37 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../srcs/libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUF_SIZE 4096

typedef struct	s_master
{
	char		*area;
	int			size;
	int			len;
	int			*tets;
	int			*coords;
	int			*max;
	int			n;
}				t_master;

void			fillit(char	*s, t_master *mst);
int				check_input(char *s);
int				*make_tets(int	**at);
int				**parse_tets(char *s);
int				count_tets(char *s);
int				*parse_tetriminos(char *s);
void			solve_tetrimino(int	*p, int len, t_master *mst);
void			set_to_dot(char c);
int				adjust_coords(int i, int s, int n);
void			ar_tetri(t_master *mst, int x, int i, int v);
int				verify_location(int i, int p, int s, t_master *mst);

#endif
