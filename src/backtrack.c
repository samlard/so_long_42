/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:26:40 by ssoumill          #+#    #+#             */
/*   Updated: 2024/08/11 14:53:00 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_cpy(t_data *map)
{
	int		i;
	char	**map_cpy;

	map_cpy = malloc(sizeof(char *) * (map->row_nbr + 2));
	i = 0;
	while (map->all_map[i])
	{
		map_cpy[i] = ft_strdup(map->all_map[i]);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int	ft_backtracking(t_data *map, char **map_cpy, int x, int y)
{
	if (map_cpy[x][y] == '1' || map_cpy[x][y] == 'z')
		return (0);
	if (map_cpy[x][y] == 'C')
		map->c_temp--;
	if (map_cpy[x][y] == 'E')
		map->e_temp--;
	map_cpy[x][y] = 'z';
	ft_backtracking(map, map_cpy, x - 1, y);
	ft_backtracking(map, map_cpy, x + 1, y);
	ft_backtracking(map, map_cpy, x, y + 1);
	ft_backtracking(map, map_cpy, x, y - 1);
	return (0);
}

void	ft_backtrack(t_data	*map)
{
	char	**map_cpy;
	int		x;
	int		y;

	x = map->x_player;
	y = map->y_player;
	map_cpy = ft_map_cpy(map);
	map->e_temp = 1;
	map->c_temp = map->count_c;
	ft_backtracking(map, map_cpy, x, y);
	if (map->c_temp != 0 || map->e_temp != 0)
	{
		ft_free_map(map_cpy);
		ft_quit("no possible way", 1, 0, map);
	}
	ft_free_map(map_cpy);
}
