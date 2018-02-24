/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 02:48:46 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/24 07:09:53 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	fillit(char	*s)
{
	int n;

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
	return ;	
}