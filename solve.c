/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:37:57 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/18 14:38:05 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "fillit.h"

static int	smallest_map(t_piece **pieces)
{
	int size;
	int width;
	int height;
	int pc;

	width = 0;
	height = 0;
	pc = 0;
	while (*pieces)
	{
		width = MAX(width, (int)(*pieces)->width);
		height = MAX(height, (int)(*pieces)->height);
		pieces++;
		pc++;
	}
	size = 2;
	while (size * size < pc * 4)
		size++;
	size = MAX(size, width);
	size = MAX(size, height);
	return (size);
}

static t_map	*new_map(int map_size)
{
	t_map *map;

	if (!(map = ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->size = map_size;
	map->placement = 0;
	return (map);
}

static	char *build_map_string(t_piece **pieces, t_map *map)
{
	char *map_str;
	int map_len;
	t_piece *cur;
	int pos;
	long long pad_shape;
	int rel;
	
	map_len = (map->size * map->size) + map->size;
	if (!(map_str = malloc(map_len + 1)))
		return (NULL);
	ft_memset(map_str, '.', map_len);
	map_str[map_len] = '\0';
	pos = 0;
	while (pos < map->size)
	{
		map_str[(pos * (map->size + 1)) + map->size] = '\n';
		pos++;
	}
	while (*pieces)
	{
		cur = *pieces;
		pad_shape = modify_shape_to(cur, map->size, cur->position);
		pos = 0;
		while (pos <= map->size * map->size)
		{
			if ((pad_shape >> ((map->size * map->size) - pos)) & 1)
			{
				rel = ((pos / map->size) * (map->size + 1)) + (pos % map->size) - 1;
				if (pos % map->size == 0)
					rel--;
				map_str[rel] = cur->id;
			}
			++pos;
		}
		pieces++;
	}
	return (map_str);
}

char	*solve(t_piece **pieces)
{
	int		map_size;
	int		solved;
	t_map	*map;
	
	map_size = smallest_map(pieces);
	solved = 0;
	map = NULL;
	while (!solved)	
	{
		if (map)
			free(map);
		map = new_map(map_size);
		solved = try(pieces, map);
		map_size++;
	}
	return (build_map_string(pieces, map));
}
