/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:40:25 by ssoumill          #+#    #+#             */
/*   Updated: 2024/08/17 15:16:56 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_data
{
	int		fd;
	int		row_nbr;
	int		column_nbr;
	void	*mlx_connection;
	void	*mlx_window;
	int		x_player;
	int		y_player;
	int		x_position;
	int		y_position;
	int		count_p;
	int		count_c;
	int		count_e;
	int		e_temp;
	int		c_temp;
	char	**all_map;
	void	*ground;
	void	*wall;
	void	*coin;
	void	*player;
	void	*exit;
	int		move;
	int		i;
	int		j;
}			t_data;

void		ft_check_input(char *map_name, t_data *map);
void		ft_check_size(t_data *map);
void		ft_check_down(t_data *map, int i, int j);
void		ft_check_middle(t_data *map, int i, int j);
void		ft_check_up(t_data *map, int i, int j);
void		ft_check_map(t_data *map, int i);
void		ft_init_map(t_data *map);
void		ft_put_image(t_data *map);
void		ft_set_struct(t_data *map);
int			ft_moove(int key, t_data *map);
void		ft_moove_up(t_data *map);
void		ft_moove_down(t_data *map);
void		ft_moove_left(t_data *map);
void		ft_moove_right(t_data *map);
void		ft_quit(char *str, int i, int j, t_data *map);
void		ft_free_struct(t_data *map);
void		ft_free_map(char **tab);
void		ft_print_move(t_data *map);
void		ft_backtrack(t_data *map);
int			ft_backtracking(t_data *map, char **map_cpy, int x, int y);
char		**ft_map_cpy(t_data *map);
int			close_game(t_data *map);
void		ft_free_struct1(t_data *map);
void		ft_quit1(char *str, int i, int j, t_data *map);

#endif