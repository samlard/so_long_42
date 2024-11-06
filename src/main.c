/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:39:24 by ssoumill          #+#    #+#             */
/*   Updated: 2024/08/12 16:49:24 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_data *map)
{
	ft_quit("you give up ?", 1, 1, map);
	return (0);
}

void	ft_print_move(t_data *map)
{
	map->move++;
	ft_printf("nombre de movement = %i position du player = (%i, %i)\n",
		map->move, map->x_player, map->y_player);
}

void	ft_set_struct(t_data *map)
{
	map->mlx_connection = mlx_init();
	if (map->mlx_connection == NULL)
		ft_quit("problem when initializing the connection", 1, 0, map);
	map->x_position = 1;
	map->y_position = 1;
	map->move = 0;
	map->wall = mlx_xpm_file_to_image(map->mlx_connection, "picture/bush.xpm",
			&map->x_position, &map->y_position);
	map->ground = mlx_xpm_file_to_image(map->mlx_connection,
			"picture/ground.xpm", &map->x_position, &map->y_position);
	map->coin = mlx_xpm_file_to_image(map->mlx_connection, "picture/fire.xpm",
			&map->x_position, &map->y_position);
	map->player = mlx_xpm_file_to_image(map->mlx_connection,
			"picture/player.xpm", &map->x_position, &map->y_position);
	map->exit = mlx_xpm_file_to_image(map->mlx_connection, "picture/castel.xpm",
			&map->x_position, &map->y_position);
	if (!map->wall || !map->ground || !map->coin || !map->player || !map->exit)
		ft_quit("problem with the images", 1, 0, map);
}

int	main(int argc, char **argv)
{
	t_data	map;

	if (argc != 2)
		ft_quit("invalid number of arguments", 0, 0, &map);
	ft_check_input(argv[1], &map);
	map.fd = open(argv[1], 'r');
	if (map.fd == -1)
		ft_quit("error when openning the file", 0, 0, &map);
	ft_check_size(&map);
	ft_check_map(&map, 1);
	ft_backtrack(&map);
	ft_set_struct(&map);
	ft_init_map(&map);
	return (0);
}
