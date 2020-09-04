/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:21:15 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/04 11:34:10 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mem_lst.h"

typedef struct		s_tet
{
	char			c;
	int				x[4];
	int				y[4];
	struct s_tet	*next;
}					t_tet;

char				*ft_read_file(int fd);
int					ft_check_char_a(char *memory, int j);
int					ft_check_count_chars(char *memory, int j);
int					ft_check_str(char *memory);
void				ft_print_map(char **map);
char				**ft_create_new_map(char **map, int size);
void				ft_change_coordinates(t_tet **tet, int x, int y);
int					ft_check_tetri_in_map(char **map, t_tet *tet, int size);
char				**ft_algorithm(char **tetri_map, t_tet *tet, int size);
void				ft_solve(t_tet *tet);
int					ft_tetri_count(char *str);
void				ft_char_a_coordinates(t_tet **tmp, char *str);
t_tet				*ft_tetri_lists(char *str);
char				**ft_remove_tetri_chars(char **map, t_tet *tet, int size);
char				**ft_insert_tetri_chars(char **map, t_tet *tet, int size);
int					ft_strlen(char *str);
void				ft_putstr(char *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
