/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:17:11 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/04 11:58:06 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_new_map(char **map, int size)
{
	int	x;
	int y;

	y = 0;
	if (!(map = (char **)mem(sizeof(char *) * size + 1)))
		return (NULL);
	while (y < size)
	{
		if (!(map[y] = (char *)mem(sizeof(char) * size + 1)))
			return (NULL);
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	map[y] = 0;
	return (map);
}

void	ft_change_coordinates(t_tet **tet, int x, int y)
{
	int pos_x;
	int	pos_y;
	int	i;

	i = 0;
	pos_x = 500;
	pos_y = 500;
	while (i < 4)
	{
		if ((*tet)->x[i] < pos_x)
			pos_x = (*tet)->x[i];
		if ((*tet)->y[i] < pos_y)
			pos_y = (*tet)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*tet)->x[i] = (*tet)->x[i] - pos_x + x;
		(*tet)->y[i] = (*tet)->y[i] - pos_y + y;
		i--;
	}
}

int		ft_check_tetri_in_map(char **map, t_tet *tet, int size)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tet->y[i] < size && tet->x[i] < size &&
			map[tet->y[i]][tet->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char	**ft_algorithm(char **tetri_map, t_tet *tet, int size)
{
	int		x;
	int		y;
	char	**map;

	if (tet->next == NULL)
		return (tetri_map);
	map = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_change_coordinates(&tet, x, y);
			if (ft_check_tetri_in_map(tetri_map, tet, size))
				map = ft_algorithm(ft_insert_tetri_chars(tetri_map, tet, size),
				tet->next, size);
			if (map)
				return (map);
			tetri_map = ft_remove_tetri_chars(tetri_map, tet, size);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	ft_solve(t_tet *tet)
{
	char	**result;
	char	**tet_map;
	int		size;

	size = 2;
	tet_map = NULL;
	tet_map = ft_create_new_map(tet_map, size);
	result = NULL;
	while (!(result = ft_algorithm(tet_map, tet, size)))
	{
		size++;
		tet_map = ft_create_new_map(tet_map, size);
	}
	ft_print_map(result);
}
