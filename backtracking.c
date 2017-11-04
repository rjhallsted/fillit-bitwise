/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:39:15 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/04 12:49:23 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include "fillit.h"

int find_placement(t_piece *piece, t_map *map, int start)
{
	
}

void place_piece(t_piece *piece, t_map *map, int placement)
{

}

void	remove_piece(t_piece *piece, t_map *map)
{

}

int	try(t_pieces **pieces, t_map *map)
{
	int place;
	int success;

	success = 0;
	place = find_placement(*pieces, map, 0);
	while (!success && place != -1)
	{
		place_piece(*pieces, map, place);
		if (*(pieces + 1) == NULL)
			return (1);
		success = try(pieces + 1, map);
		if (!success)
		{
			remove_piece(*pieces, map);
			place = find_placement(*pieces, map, place + 1);
		}
	}
	return (success);
}
