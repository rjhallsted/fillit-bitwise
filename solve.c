/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:37:57 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/05 15:19:15 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "fillit.h"

#include <stdio.h>

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
	int i;
	int j;
	int pos;
	int map_len;

	map_len = (map->size * map->size) + map->size;
	if (!(map_str = ft_strnew(map_len)))
		return (NULL);
	i = 0;
	while (i < map->size)
	{
		map_str[(i * (map->size + 1)) + map->size] = '\n';
		i++;
	}
	while (*pieces)
	{
		i = 0;
		while (i < (*pieces)->height)
		{
			j = 0;
			while (j < (*pieces)->width)
			{
				pos = (*pieces)->position + (i * (map->size + 1)) + j;
				map_str[pos] = (*pieces)->id;
				j++;
			}
			i++;
		}
		pieces++;
	}
	i = 0;
	while (i < map_len)
	{
		if (map_str[i] == '\0')
			map_str[i] = '.';
		i++;
	}
	return (map_str);
}

char	*solve(t_piece **pieces)
{
	int		map_size;
	int		solved;
	t_map	*map;
	
	map_size = smallest_map(pieces);
	printf("map size: %d\n", map_size);
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
	printf("solved(%d)\n", map->size);
	printf("%s\n", ft_itoa_base(map->placement, 2));
	return (build_map_string(pieces, map));
}
