/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:36:32 by ssoumill          #+#    #+#             */
/*   Updated: 2024/08/17 14:33:19 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_data *map, int i)
{
	ft_check_up(map, 0, 0);
	while (i < map->row_nbr)
	{
		ft_check_middle(map, i, 0);
		i++;
	}
	ft_check_down(map, map->row_nbr, 0);
}

void	ft_check_up(t_data *map, int i, int j)
{
	map->count_p = 0;
	map->count_c = 0;
	map->count_e = 0;
	if ((int)ft_strlen(map->all_map[i]) - 1 != map->column_nbr)
		ft_quit("invalid map", 1, 0, map);
	while (map->all_map[i][j])
	{
		if (map->all_map[i][j] != '1')
			ft_quit("invalid map", 1, 0, map);
		j++;
	}
}

void	ft_check_middle(t_data *map, int i, int j)
{
	while (map->all_map[i][j])
	{
		if (j == 0 && map->all_map[i][j] != '1')
			ft_quit("invalid map", 1, 0, map);
		if (j == map->column_nbr && map->all_map[i][j] != '1')
			ft_quit("invalid map", 1, 0, map);
		if ((int)ft_strlen(map->all_map[i]) - 1 != map->column_nbr)
			ft_quit("invalid map", 1, 0, map);
		if (map->all_map[i][j] != '1' && map->all_map[i][j] != '0'
			&& map->all_map[i][j] != 'E' && map->all_map[i][j] != 'P'
			&& map->all_map[i][j] != 'C')
			ft_quit("bad caracter", 1, 0, map);
		if (map->all_map[i][j] == 'P')
		{
			map->count_p++;
			map->x_player = i;
			map->y_player = j;
		}
		if (map->all_map[i][j] == 'E')
			map->count_e++;
		if (map->all_map[i][j] == 'C')
			map->count_c++;
		j++;
	}
}

void	ft_check_down(t_data *map, int i, int j)
{
	if (map->count_c < 1)
		ft_quit("no collectible", 1, 0, map);
	if (map->count_e != 1)
		ft_quit("invalid number of exit", 1, 0, map);
	if (map->count_p != 1)
		ft_quit("invalid mumber of player", 1, 0, map);
	if ((int)ft_strlen(map->all_map[i]) - 1 != map->column_nbr)
		ft_quit("invalid map", 1, 0, map);
	while (map->all_map[i][j])
	{
		if (map->all_map[i][j] != '1')
			ft_quit("invalid map", 1, 0, map);
		j++;
	}
}
