/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debaxter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:11:26 by debaxter          #+#    #+#             */
/*   Updated: 2018/05/27 20:11:28 by debaxter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	*ft_helper(int new_lines, int pieces, int dot, char *str)
{
	int *tmp;
	int i;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * 3);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			new_lines++;
		else if (str[i] == '#')
			pieces++;
		else if (str[i] == '.')
			dot++;
		i++;
	}
	if (str[i - 1] == '\n')
	{
		EXIT_MACRO;
	}
	tmp[0] = new_lines;
	tmp[1] = pieces;
	tmp[2] = dot;
	return (tmp);
}

int			ft_piece_count(char *str)
{
	VAL_MACRO;
	if (!*str)
	{
		EXIT_MACRO;
	}
	if (str[0] != '.' && str[0] != '#')
	{
		EXIT_MACRO;
	}
	tmp = ft_helper(new_lines, pieces, dot, str);
	HELPER_MACRO;
	if (new_lines == 3 && pieces == 4 && dot == 12)
		return (1);
	else if (pieces * 3 == dot && pieces != 4)
		pieces = pieces / 4;
	else
	{
		EXIT_MACRO;
	}
	return (pieces);
}

int			ft_sqrt_up(int n)
{
	int i;

	i = 1;
	if (n == 0)
		return (0);
	while (i * i < n)
		i++;
	if (n % i == 0)
		return (i);
	else
		return ((n + i - 1) / i);
}
