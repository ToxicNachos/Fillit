/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pieces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:27:20 by pkumar            #+#    #+#             */
/*   Updated: 2018/06/12 15:27:21 by pkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	***ft_malloc_coords(char **boxes)
{
	COORDS_MACRO;
	b = 0;
	while (boxes[a])
		a++;
	if (!(coords = (char ***)malloc(sizeof(char **) * a + 1)))
		return (NULL);
	while (b <= a)
	{
		coords[b] = (char **)malloc(sizeof(char *) * 4 + 1);
		c = 0;
		while (c <= 5)
		{
			coords[b][c] = (char*)malloc(sizeof(char) * 5 + 1);
			c++;
		}
		b++;
	}
	return (coords);
}

static char	**ft_box_malloc(char **boxes, int box_count)
{
	int i;

	i = -1;
	if (!(boxes = (char **)malloc((sizeof(char*) * box_count + 1))))
		return (NULL);
	while (++i < box_count)
		boxes[i] = (char *)malloc(sizeof(char) * (BOX_SIZE));
	boxes[box_count] = NULL;
	return (boxes);
}

static char	***ft_twotothree(char **boxes, int box_count)
{
	int d;
	box_count = 0;

	COORDS_MACRO;
	coords = ft_malloc_coords(boxes);
	while (boxes[a])
	{
		b = 0;
		c = 0;
		d = 0;
		while (boxes[a][b] != '\0')
		{
			coords[a][c][d++] = boxes[a][b++];
			if (boxes[a][b] == '\n' || boxes[a][b] == '\0')
			{
				coords[a][c][d] = '\0';
				d = 0;
				c++;			
			}
		}
		coords[a][c] = NULL;
		a++;
	}
	coords[a] = NULL;
	return (coords);
}

char		**ft_split_pieces(char *str)
{
	SPLIT_PIECES;
	while (*str != '\0')
		while (box < box_count)
		{
			s = 0;
			FUCK_IT;
			if (*str != '\n' && box != box_count - 1)
			{
				EXIT_MACRO;
			}
			else
				str++;
			boxes[box++][s] = '\0';
		}
	while (i < box)
		if (ft_validate_piece(boxes[i]) == 1)
			i++;
		else
		{
			EXIT_MACRO;
		}
	coords = ft_twotothree(boxes, box_count);
	MOVE_LEFT;
	for (int w = 0; coords[w]; w++)
		ft_print_map(coords[w]);
	write (1, "\n\n", 2);
	ft_placer(coords, map_size);
	return (boxes);
}
