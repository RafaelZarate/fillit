/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 01:16:09 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/23 03:53:15 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int ac,char  **av)
{
	int	fd;
	int	ret;
	char	buf[BUF_SIZE + 1];

	if (ac == 1 || ac > 2)
	{
		ft_putstr_fd("you dumb piece of shittttt\n", 2);
		return (0);
	}
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("Couldn't open file\n", 2);
			return (0);
		}
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		ft_putstr(buf);
		fillit(buf);
		if (close(fd) == -1)
		{
			ft_putstr_fd("Couldn't close file\n", 2);
			return (0);
		}
	}
	return (0);
}