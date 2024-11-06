/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:39:13 by ssoumill          #+#    #+#             */
/*   Updated: 2024/08/11 14:53:14 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_input(char *map_name, t_data *map)
{
	if (ft_strlen(map_name) < 5)
		ft_quit("bad map name", 0, 0, map);
	while (*map_name && *map_name != '.')
		map_name++;
	if (ft_strcmp(map_name, ".ber") != 0)
		ft_quit("bad map name", 0, 0, map);
}

void	ft_check_size(t_data *map)
{
	char	*str;
	char	*temp;
	char	*temp2;

	str = ft_strdup("");
	map->row_nbr = -1;
	while (1)
	{
		temp = get_next_line(map->fd);
		if (temp == NULL)
			break ;
		temp2 = str;
		str = ft_strjoin(str, temp);
		free(temp2);
		map->column_nbr = ft_strlen(temp);
		map->row_nbr++;
		free(temp);
	}
	map->all_map = ft_split(str, '\n');
	map->column_nbr--;
	free(str);
	free(temp);
}
