/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:37:57 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/05 12:54:56 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "fillit.h"

#include <stdio.h>

static int	count_pieces(t_piece **pieces)
{
	int i;

	i = 0;
	while (*pieces++)
		i++;
	return (i);
}

static int	smallest_map(int pc)
{
	int size;

	size = 2;
	while (size * size < pc * 4)
		size++;
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

//maybe add compensation for min piece width and height to the smallest map size calc

char	*solve(t_piece **pieces)
{
	int		pc;
	int		map_size;
	int		solved;
	t_map	*map;
	
	pc = count_pieces(pieces);
	map_size = smallest_map(pc);
	solved = 0;
	map = NULL;
	/* while (!solved) */
	/* { */
	/* 	if (map) */
	/* 		free(map); */
	/* 	map = new_map(map_size); */
	/* 	solved = try(pieces, map); */
	/* 	map_size++; */
	/* } */

	map = new_map(3);
	while (*pieces)
	{
		try(pieces, map);
		pieces++;
	}
	return (NULL);
	
//	printf("solved\n");
	//build map_string.
	//once true, build map string. (string of size^2 + size + 1)
	// 		each piece has id and position, from bottom-right corner. Write to map as necessary.
}
