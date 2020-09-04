/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:38:14 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/04 11:57:54 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_tetri_count(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			result++;
		i++;
	}
	result = result / 4;
	return (result);
}

void	ft_char_a_coordinates(t_tet **tmp, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

t_tet	*ft_tetri_lists(char *str)
{
	int		c_tetri;
	int		next_block;
	char	c;
	t_tet	*stock;
	t_tet	*tmp;

	next_block = 0;
	c = 'A';
	c_tetri = ft_tetri_count(str);
	if (!(stock = (t_tet *)mem(sizeof(t_tet))))
		return (NULL);
	tmp = stock;
	while (c_tetri > 0)
	{
		tmp->c = c;
		ft_char_a_coordinates(&tmp, ft_strsub(str, 0 + next_block, 20));
		if (!(tmp->next = (t_tet *)mem(sizeof(t_tet))))
			return (NULL);
		tmp = tmp->next;
		c_tetri--;
		c++;
		next_block = next_block + 21;
	}
	tmp->next = NULL;
	return (stock);
}

char	**ft_remove_tetri_chars(char **map, t_tet *tet, int size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == tet->c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

char	**ft_insert_tetri_chars(char **map, t_tet *tet, int size)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tet->y[i] == y && tet->x[i] == x)
			{
				map[y][x] = tet->c;
				i++;
			}
			x++;
		}
		y++;
	}
	return (map);
}
