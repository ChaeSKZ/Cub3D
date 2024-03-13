/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:26:40 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/13 15:55:42 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_texture_and_colors(char **file)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (file[++i])
	{
		if (file[i][0] == 'N' && file[i][1] == 'O' && file[i][2] == ' ')
			count++;
		else if (file[i][0] == 'S' && file[i][1] == 'O' && file[i][2] == ' ')
			count++;
		else if (file[i][0] == 'W' && file[i][1] == 'E' && file[i][2] == ' ')
			count++;
		else if (file[i][0] == 'E' && file[i][1] == 'A' && file[i][2] == ' ')
			count++;
		else if (file[i][0] == 'F' && file[i][1] == ' ')
			count++;
		else if (file[i][0] == 'C' && file[i][1] == ' ')
			count++;
		if (count == 6)
			return (i + 1);
	}
	return (false);
}

bool	is_map_line(char *line)
{
	int	i;

	i = -1;
	if (!line)
		return (false);
	while (line[++i])
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			return (true);
	return (false);
}

int	get_map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i] && is_map_line(map[i]))
		i++;
	return (i);
}

t_map_enum	*copy_line(t_map_enum *map, char *line)
{
	int	i;

	i = -1;
	map = malloc(sizeof(t_map_enum) * (ft_strlen(line) - 1));
	if (!map)
		return (printf("error: memory allocation failed.\n"), NULL);
	while (line[++i])
	{
		if (line[i] == ' ')
			map[i] = SPACE;
		if (line[i] == '1')
			map[i] = WALL;
		if (line[i] == '0')
			map[i] = VOID;
		if (line[i] == 'N')
			map[i] = NORTH;
		if (line[i] == 'S')
			map[i] = SOUTH;
		if (line[i] == 'E')
			map[i] = EAST;
		if (line[i] == 'W')
			map[i] = WEST;
	}
	return (map);
}

bool	copy_map(char **map, t_map_data *data)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (map[++i])
		if (is_map_line(map[i]))
			break ;
	if (!map[i])
		return (printf("error: no map in .cub file\n"), false);
	data->height = get_map_size(&map[i]);
	data->width = -1;
	data->map = malloc(sizeof(t_map_enum *) * data->height);
	if (!data->map)
		return (printf("error: memory allocation failed.\n"), false);
	while (map[i] && is_map_line(map[i]))
	{
		if (ft_strlen(map[i]) > data->width)
			data->width = ft_strlen(map[i]) - 1;
		data->map[n] = copy_line(data->map[n], map[i]);
		n++;
		i++;
	}
	return (true);
}

bool	get_map(char **file, t_map_data *data)
{
	int	skip;

	skip = skip_texture_and_colors(file);
	if (!copy_map(&file[skip], data))
		return (false);
	return (true);
}
