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

int		ft_piece_count(char *str)
{
	VAL_MACRO;
	if (!*str)
		return (0);
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
	if (new_lines == 4 && pieces == 4)
		return (1);
	else if (pieces * 3 == dot)
		pieces = pieces / 4;
	else
	{
		EXIT_MACRO;
	}
	return (pieces);
}

int		ft_sqrt_up(int n)
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
