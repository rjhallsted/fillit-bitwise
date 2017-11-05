/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:39:15 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/05 12:54:39 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include "fillit.h"

#include <stdio.h>

int pad_shape(t_piece *piece, int pad_by)
{
	int num;
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
		if (pad_by > 0)
			num = num << pad_by;
		lines--;
	}
	return (num);
}


/* int	find_placement(t_piece *piece, t_map *map, int start) */
/* { */

/* } */

/* static void place_piece(t_piece *piece, t_map *map, int placement) */
/* { */

/* } */

/* static void	remove_piece(t_piece *piece, t_map *map) */
/* { */

/* } */

int	try(t_piece **pieces, t_map *map)
{
	printf("trying\n");
	printf("%s -> %s\n", ft_itoa_base((*pieces)->shape, 2), ft_itoa_base(pad_shape(*pieces, -1), 2));
	return (1);
	/* int place; */
	/* int success; */

	/* success = 0; */
	/* place = find_placement(*pieces, map, (map->size * map->size) - 1); */
	/* while (!success && place != -1) */
	/* { */
	/* 	place_piece(*pieces, map, place); */
	/* 	if (*(pieces + 1) == NULL) */
	/* 		return (1); */
	/* 	success = try(pieces + 1, map); */
	/* 	if (!success) */
	/* 	{ */
	/* 		remove_piece(*pieces, map); */
	/* 		place = find_placement(*pieces, map, place - 1); */
	/* 	} */
	/* } */
	/* return (success); */
}
