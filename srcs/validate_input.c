/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 03:55:46 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/24 07:41:51 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static	int	check_pounds(int **p, char	*s)
{
	int i;
	int	i2;
	int	sum;

	i = -1;
	while (++i < count_tets(s))
	{
		i2 = -1;
		sum = 0;
		while (++i2 < 16)
			sum += p[i][i2];
		if (sum != 4)
			return (0);
	}
	return (1);
}

static	int	check_chars(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

 static	int	check_nl(char *s)
 {
 	int i;
	int	c;

 	i = 0;
	c = 0;
 	while (s[i])
 	{
 		if (((i - c + 1) % 5 == 0) && s[i] != '\n' && i != 0)
		 	return (0);
		else if (((i - c) % 20 == 0) && s[i] != '\n' && i != 0)
			return (0);
		if ((i - c) % 20 == 0 && i != 0)
		{
			c++;
			i++;
			if (s[i] == '\n')
		 		return (0);
		}
 		i++;		
 	}
	return (1);
}

int	check_form(int	*p, int i, int c)
{
	printf("%i\t%i\t%i\t%i\n", p[i], p[i + 1], i, c);
	if (c == 3)
		return (1);
	if (i > 19)
		return (0);
	if (i > 6)
	{
		if (p[i - 1] == 1 && p[i - 2] == 1 && c == 2)
			return (1);
	}
	if (i < 14)
	{
		if (p[i + 1] == 1 && p[i + 4] == 1 && p[i + 5] == 1)
			return (1);
	}
	if (i > 5)
	{
		if (p[i - 1] == 1)
			c++;
	}
	// if (i < 19)
	//  {
		if (i < 19 && p[i + 1] == 1)
			check_form(p, i + 1, c + 1);
	//}
	if (i < 15)
	{
		if (p[i + 4] == 1)
			check_form(p, i + 4, c + 1);
	}
	return (0);
}

int	check_input(char *s)
{
	size_t	i;
	int		**a;

	i = 0;
	if (!s[i])
		return (-1);
	else if (check_chars(s) && check_nl(s))
	{
		a = parse_tets(s);
		if (check_pounds(a, s))
		{
			printf("%d", check_form(a[15], 0, 0));
		}
			
	}
	return (1);
}