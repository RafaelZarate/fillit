/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 01:16:09 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/23 02:50:46 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int ac,char  **av)
{
	int	fd;
	int	ret;
	char	buf[BUF_SIZE + 1];

	if (!ac || ac > 1)
	{
		ft_putstr_fd(2, "you dumb piece of shittttt");
	}
	else if (ac == 1)
	{
		fd = open(av[0], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd(2, "Couldn't open file");
			return (0);
		}
		ret = read(fd, buf, BUF_SIZE);
		ret = '\0';
		fillit(ret);
		if (close(fd) == -1)
		{
			ft_pustr_fd(2, "Couldn't close file");
			return (0);
		}
	}
	return (0);
}