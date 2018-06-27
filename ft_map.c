/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:36:26 by pkumar            #+#    #+#             */
/*   Updated: 2018/06/19 16:36:27 by pkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(char **map)
{
	int i;
	int j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			write(1, &map[j][i], 1);
			i++;
		}
		j++;
		write(1, "\n", 1);
	}
}

void	ft_strdel(char **as)
{
	if (as == NULL)
		return ;
	free(*as);
	*as = NULL;
}

char	**ft_make_map(int p)
{
	MAP_MACRO;
	if (!(map = (char **)malloc((sizeof(char*) * p + 1))))
		return (NULL);
	while (++i < p)
		map[i] = (char *)malloc(sizeof(char) * p + 1);
	while (x < p)
	{
		y = 0;
		while (y < p)
			map[x][y++] = '.';
		map[x++][y] = '\0';
	}
	map[x] = NULL;
	return (map);
}
