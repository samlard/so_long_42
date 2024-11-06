/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:32:38 by ssoumill          #+#    #+#             */
/*   Updated: 2024/08/17 16:22:33 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_struct(t_data *map)
{
	if (map->mlx_connection)
		mlx_destroy_window(map->mlx_connection, map->mlx_window);
	if (map->ground != NULL)
		mlx_destroy_image(map->mlx_connection, map->ground);
	if (map->coin != NULL)
		mlx_destroy_image(map->mlx_connection, map->coin);
	if (map->exit != NULL)
		mlx_destroy_image(map->mlx_connection, map->exit);
	if (map->player != NULL)
		mlx_destroy_image(map->mlx_connection, map->player);
	if (map->wall != NULL)
		mlx_destroy_image(map->mlx_connection, map->wall);
}

void	ft_free_struct1(t_data *map)
{
	if (map->ground != NULL)
		mlx_destroy_image(map->mlx_connection, map->ground);
	if (map->coin != NULL)
		mlx_destroy_image(map->mlx_connection, map->coin);
	if (map->exit != NULL)
		mlx_destroy_image(map->mlx_connection, map->exit);
	if (map->player != NULL)
		mlx_destroy_image(map->mlx_connection, map->player);
	if (map->wall != NULL)
		mlx_destroy_image(map->mlx_connection, map->wall);
}

void	ft_quit1(char *str, int i, int j, t_data *map)
{
	if (str)
		ft_putendl_fd(str, 2);
	if (j == 1)
		ft_free_struct1(map);
	if (i == 1)
		ft_free_map(map->all_map);
	exit(1);
}

void	ft_quit(char *str, int i, int j, t_data *map)
{
	if (str)
		ft_putendl_fd(str, 2);
	if (j == 1)
		ft_free_struct(map);
	if (i == 1)
		ft_free_map(map->all_map);
	exit(1);
}
