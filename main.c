/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:53:30 by pkumar            #+#    #+#             */
/*   Updated: 2018/06/20 15:53:32 by pkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		x;
	char	buf[MAX_FILLIT_FILE + CUSHION];

	if (argc != 1)
	{
		EXIT_MACRO;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		EXIT_MACRO;
	}
	if (!(x = read(fd, buf, MAX_FILLIT_FILE + CUSHION)))
	{
		EXIT_MACRO;
	}
	buf[x] = '\0';
	if (x > MAX_FILLIT_FILE)
	{
		EXIT_MACRO;
	}
	ft_split_pieces(buf);
	close(fd);
	return (0);
}
