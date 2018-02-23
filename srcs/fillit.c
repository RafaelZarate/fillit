/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 02:48:46 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/23 04:36:22 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	fillit(char	*s)
{
	if (!check_input(s))
	{
		ft_putendl_fd("Invalid parameter passed breihhhh", 2);
		return ;
	}
	else
		ft_putendl("GOOD TO GO");
}