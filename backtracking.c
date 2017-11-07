/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:39:15 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/06 18:25:43 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include "fillit.h"

#include <stdio.h>

static long long pad_shape(t_piece *piece, int pad_by)
{
	long long num;
	int tmp;
	int lines;
	int shift;

	if (pad_by == 0)
		return (piece->shape);
	num = 0;
	lines = piece->height - 1;
	shift = (pad_by > 0) ? 4 : 4 + pad_by;
	while (lines >= 0)
	{
		if (num)
			num = num << shift;
		tmp = (piece->shape >> (lines * 4)) & 0xf;
		num = num | tmp;
		if (pad_by > 0 && lines != 0)
			num = num << pad_by;
		lines--;
	}
	return (num);
}

static long long	modify_shape_to(t_piece *piece, t_map *map, int pos)
{
	long long morphed;
	int shift_by;

	morphed = pad_shape(piece, map->size - 4);
	shift_by = pos - (((piece->height - 1) * map->size) + piece->width);
	return (morphed << shift_by);
}

static	int find_placement(t_piece *piece, t_map *map, int start)
{
	long long padded_num;
	int can_place;
	int min_place;

	can_place = 0;
	min_place = ((piece->height - 1) * map->size) + piece->width;
	while (!can_place && start >= min_place)
	{
		if (start + (int)piece->width > (start + map->size - (start % map->size)))
			can_place = 0;
		else
		{
			padded_num = modify_shape_to(piece, map, start);
			can_place = !(padded_num & map->placement);
		}
		if (!can_place)
			start--;
	}
	return ((can_place) ? start : -1);
}

static void place_piece(t_piece *piece, t_map *map, int placement)
{
	long long padded_num;

	padded_num = modify_shape_to(piece, map, placement);
	piece->position = placement;
	map->placement = map->placement | padded_num;
}

static void	remove_piece(t_piece *piece, t_map *map)
{
	long long padded_num;
	
	padded_num = modify_shape_to(piece, map, piece->position);
	map->placement = map->placement ^ padded_num;
}

int	try(t_piece **pieces, t_map *map)
{
	int place;
	int success;

	success = 0;
	place = find_placement(*pieces, map, (map->size * map->size));
	while (!success && place != -1)
	{
		place_piece(*pieces, map, place);
		if (*(pieces + 1) == NULL)
			return (1);
		success = try(pieces + 1, map);
		if (!success)
		{
			remove_piece(*pieces, map);
			place = find_placement(*pieces, map, place - 1);
		}
	}
	return (success);
}
