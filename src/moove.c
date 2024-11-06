/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:27:39 by ssoumill          #+#    #+#             */
/*   Updated: 2024/08/12 16:54:54 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_moove(int key, t_data *map)
{
	if (key == 13)
	{
		ft_moove_up(map);
	}
	if (key == 0)
		ft_moove_left(map);
	if (key == 1)
		ft_moove_down(map);
	if (key == 2)
		ft_moove_right(map);
	if (key == 53)
	{
		ft_quit("You escape the game", 1, 1, map);
	}
	return (0);
}

void	ft_moove_up(t_data *map)
{
	if (map->all_map[map->x_player - 1][map->y_player] != '1')
	{
		map->x_player--;
		ft_print_move(map);
		mlx_clear_window(map->mlx_connection, map->mlx_window);
		if (map->all_map[map->x_player][map->y_player] == 'C')
		{
			map->all_map[map->x_player][map->y_player] = '0';
			map->count_c--;
		}
		if (map->all_map[map->x_player][map->y_player] == 'E'
			&& map->count_c == 0)
		{
			ft_put_image(map);
			ft_quit("Congratulation you finish the game", 1, 1, map);
		}
		ft_put_image(map);
	}
}

void	ft_moove_down(t_data *map)
{
	if (map->all_map[map->x_player + 1][map->y_player] != '1')
	{
		map->x_player++;
		ft_print_move(map);
		mlx_clear_window(map->mlx_connection, map->mlx_window);
		if (map->all_map[map->x_player][map->y_player] == 'C')
		{
			map->all_map[map->x_player][map->y_player] = '0';
			map->count_c--;
		}
		if (map->all_map[map->x_player][map->y_player] == 'E'
			&& map->count_c == 0)
		{
			ft_put_image(map);
			ft_quit("Congratulation you finish the game", 1, 1, map);
		}
		ft_put_image(map);
	}
}

void	ft_moove_left(t_data *map)
{
	if (map->all_map[map->x_player][map->y_player - 1] != '1')
	{
		map->y_player--;
		ft_print_move(map);
		mlx_clear_window(map->mlx_connection, map->mlx_window);
		if (map->all_map[map->x_player][map->y_player] == 'C')
		{
			map->all_map[map->x_player][map->y_player] = '0';
			map->count_c--;
		}
		if (map->all_map[map->x_player][map->y_player] == 'E'
			&& map->count_c == 0)
		{
			ft_put_image(map);
			ft_quit("Congratulation you finish the game", 1, 1, map);
		}
		ft_put_image(map);
	}
}

void	ft_moove_right(t_data *map)
{
	if (map->all_map[map->x_player][map->y_player + 1] != '1')
	{
		map->y_player++;
		ft_print_move(map);
		mlx_clear_window(map->mlx_connection, map->mlx_window);
		if (map->all_map[map->x_player][map->y_player] == 'C')
		{
			map->all_map[map->x_player][map->y_player] = '0';
			map->count_c--;
		}
		if (map->all_map[map->x_player][map->y_player] == 'E'
			&& map->count_c == 0)
		{
			ft_put_image(map);
			ft_quit("Congratulation you finish the game", 1, 1, map);
		}
		ft_put_image(map);
	}
}
