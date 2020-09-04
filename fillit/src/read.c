/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:51:55 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/04 12:00:39 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read_file(int fd)
{
	int		bytes;
	int		i;
	char	c;
	char	*str;

	i = 0;
	str = NULL;
	bytes = read(fd, &c, 1);
	if (bytes <= 0)
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	if (bytes == 1)
	{
		if (!(str = (char *)mem(sizeof(char) * 600)))
			return (NULL);
		while (bytes != '\0')
		{
			str[i++] = c;
			bytes = read(fd, &c, 1);
		}
		str[i] = '\0';
	}
	return (str);
}

int		ft_check_char_a(char *memory, int j)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i + j < 20 + j)
	{
		if (memory[i + j] == '#')
		{
			if ((i + j + 1) < (20 + j) && memory[i + j + 1] == '#')
				count++;
			if ((i + j - 1) >= (0 + j) && memory[i + j - 1] == '#')
				count++;
			if ((i + j + 5) < (20 + j) && memory[i + j + 5] == '#')
				count++;
			if ((i + j - 5) >= (0 + j) && memory[i + j - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		ft_check_count_chars(char *memory, int j)
{
	int	a;
	int	point;
	int	n;
	int	i;

	a = 0;
	point = 0;
	n = 0;
	i = 0;
	while (i + j < 20 + j && memory[i + j] != '\0')
	{
		if (memory[i + j] == '#')
			a++;
		if (memory[i + j] == '.')
			point++;
		if (memory[i + j] == '\n')
			n++;
		i++;
	}
	if (a == 4 && point == 12 && n == 4)
		return (1);
	return (0);
}

int		ft_check_str(char *memory)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (memory[i + j] != '\0')
	{
		if (!(ft_check_char_a(memory, j) && ft_check_count_chars(memory, j)))
			return (0);
		i = 19;
		if (memory[i + j] == '\n' && memory[i + j + 1] == '\0')
			return (1);
		if (memory[i + j] == '\n' && memory[i + j + 1] == '\n' &&
		(memory[i + j + 2] == '.' || memory[i + j + 2] == '#'))
			j = j + 21;
		else
			return (0);
		i = 0;
	}
	return (0);
}

void	ft_print_map(char **map)
{
	int	i;

	if (map == NULL)
	{
		write(1, "error\n", 6);
		exit(0);
	}
	i = 0;
	while (map[i] != 0)
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
		i++;
	}
}
