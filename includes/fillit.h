/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 01:48:59 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/23 04:51:56 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define BUF_SIZE 4096

#include "../srcs/libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef struct	s_list
{
	char			*l1;
	char			*l2;
	char			*l3;
	char			*l4;
	struct	s_list	*next;
}				raw_list;

typedef struct	s_list
{
	int				type;
	int				orientation;
	struct	s_list	*next;
}				tet_list;

void			fillit(char	*s);
int				check_input(char *s);

#endif