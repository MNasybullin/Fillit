/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:28:47 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/04 11:40:59 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*memory;
	int		fd;
	t_tet	*tet;

	set_m();
	if (argc != 2)
	{
		ft_putstr("map not found | use ./fillit 'filename'\n");
		del_memory();
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(memory = ft_read_file(fd)))
		return (0);
	if (!ft_check_str(memory))
	{
		write(1, "error\n", 6);
		del_memory();
		return (0);
	}
	close(fd);
	tet = ft_tetri_lists(memory);
	ft_solve(tet);
	del_memory();
	return (0);
}
