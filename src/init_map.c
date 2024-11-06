/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:21:21 by ssoumill          #+#    #+#             */
/*   Updated: 2024/08/12 21:51:26 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(t_data *map)
{
	if ((map->column_nbr + 1) * 64 > 2560 || (map->row_nbr + 1) * 64 > 1344)
		ft_quit1("map to large", 1, 1, map);
	map->mlx_window = mlx_new_window(map->mlx_connection, (map->column_nbr + 1)
			* 64, (map->row_nbr + 1) * 64, "ma fenetre test");
	if (map->mlx_window == NULL)
		ft_quit("problem when initializing the window", 1, 1, map);
	ft_put_image(map);
	mlx_key_hook(map->mlx_window, ft_moove, map);
	mlx_hook(map->mlx_window, 17, 1L >> 17, close_game, map);
	mlx_loop(map->mlx_connection);
}

void	ft_put_image(t_data *map)
{
	map->i = 0;
	while (map->all_map[map->i])
	{
		map->j = 0;
		while (map->all_map[map->i][map->j])
		{
			mlx_put_image_to_window(map->mlx_connection, map->mlx_window,
				map->ground, map->j * 64, map->i * 64);
			if (map->all_map[map->i][map->j] == '1')
				mlx_put_image_to_window(map->mlx_connection, map->mlx_window,
					map->wall, map->j * 64, map->i * 64);
			if (map->all_map[map->i][map->j] == 'C')
				mlx_put_image_to_window(map->mlx_connection, map->mlx_window,
					map->coin, map->j * 64, map->i * 64);
			if (map->all_map[map->i][map->j] == 'E')
				mlx_put_image_to_window(map->mlx_connection, map->mlx_window,
					map->exit, map->j * 64, map->i * 64);
			if (map->all_map[map->x_player][map->y_player])
				mlx_put_image_to_window(map->mlx_connection, map->mlx_window,
					map->player, map->y_player * 64, map->x_player * 64);
			map->j++;
		}
		map->i++;
	}
}
