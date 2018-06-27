/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:35:43 by pkumar            #+#    #+#             */
/*   Updated: 2018/06/10 18:35:44 by pkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_first_part(char *str, int i, int v)
{
	if (i == 0)
	{
		if (str[i + 1] == '#')
			v++;
		if (str[i + LINE_SIZE] == '#')
			v++;
	}
	if (i > 0 && i < 5)
	{
		if (str[i + 1] == '#')
			v++;
		if (str[i - 1] == '#')
			v++;
		if (str[i + LINE_SIZE] == '#')
			v++;
	}
	return (v);
}

static int	ft_second_part(char *str, int i, int v)
{
	if (i >= 5 && i < 15)
	{
		if (str[i + 1] == '#')
			v++;
		if (str[i - 1] == '#')
			v++;
		if (str[i - LINE_SIZE] == '#')
			v++;
		if (str[i + LINE_SIZE] == '#')
			v++;
	}
	return (v);
}

static int	ft_last_part(char *str, int i, int v)
{
	if (i >= 15 && i < 20)
	{
		if (str[i + 1] == '#')
			v++;
		if (str[i - 1] == '#')
			v++;
		if (str[i - LINE_SIZE] == '#')
			v++;
	}
	return (v);
}

static int	ft_while_stat(char *str)
{
	int i;
	int v;

	i = 0;
	v = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			v = ft_first_part(str, i, v);
			v = ft_second_part(str, i, v);
			v = ft_last_part(str, i, v);
		}
		i++;
	}
	return (v);
}

int			ft_validate_piece(char *str)
{
	int		v;

	v = 0;
	if (!*str)
		return (0);
	v = ft_while_stat(str);
	if (v == 6 || v == 8)
		return (1);
	else
	{
		write(1, "error\n", 6);
		exit(-1);
	}
	return (0);
}
