/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 01:48:59 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/24 04:57:40 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define BUF_SIZE 4096

#include "../srcs/libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

void			fillit(char	*s);
int				check_input(char *s);
int			*make_tets(int	**at);
int			**parse_tets(char *s);
int			count_tets(char *s);
void		solve_tetrimino(int	**p);

#endif