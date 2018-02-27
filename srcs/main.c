/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 01:16:09 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/27 14:35:33 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int ac,char  **av)
{
	int	fd;
	int	ret;
	char	buf[BUF_SIZE + 1];
	t_tetris tet;


	// tet.length = 1;
	av++;
	ft_bzero(&tet, (sizeof(tet)));
	if (ac == 1 || ac > 2)
	{
		ft_putendl_fd("you dumb piece of shittttt\n", 2);
		return (0);
	}
	else if (ac == 2)
	{
		fd = open("test2.txt", O_RDONLY);
		if (fd == -1)
		{
			ft_putendl_fd("Couldn't open file\n", 2);
			return (0);
		}
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		fillit(buf, &tet);
		if (close(fd) == -1)
		{
			ft_putendl_fd("Couldn't close file\n", 2);
			return (0);
		}
	}
	return (0);
}