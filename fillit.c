/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:06:10 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/23 20:03:47 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

//run backtracking algorithm
//print map

/*
** Takes a single line from the file (assuming its not just the newline)
** and checks to make sure it's the right length, the characters are valid,
** and uses bitshifting to convert it to a integer representation of the line.
*/

static int valid_line_to_int(char *line)
{
	int i;
	int j;
	int	shift;

	if (ft_strlen(line) != 4)
		return (-1);
	i = 0;
	j = 0;
	while (j < 4)
	{
		if (line[j] != '#' && line[j] != '.')
			return (-1);
		i = i << 1;
		if (line[j] == '#')
			i += 1;
		j++;
	}
	return (i);
}

/*
** pc is intialized at -1, and immediately incremented to 0
** so the highest valid piece index is 25, not 25
**/

/*
** 1) Add connection check.
*/

static int *get_validated_pieces(int fd)
{
	char	*line;
	int		*pieces;
	int		i;
	int		pc;
	int		tmp;

	i = 0;
	pc = -1;
	while (get_next_line(fd, &line))
	{
		if (i % 5 == 0)
		{
			pc++;
			pieces = ft_realloc(pieces, sizeof(int) * (i + 1));
			pieces[pc] = 0;
		}
		if (i % 5 != 4)
		{
			if ((tmp = valid_line_to_int(line)) == -1)
			{
				free(line);
				free(pieces);
				return (NULL):
			}
			pieces[i] = (pieces[i] << 4) + tmp;
		}
		else
		{
			if (line != NULL)
			{
				free(line);
				free(pieces);
				return (NULL);
			}
		}
		i++;
		free(line);
	}
	if (pc > 25)
	{
		free(pieces);
		return (NULL);
	}
	pieces[pc + 1] = NULL;
	return (pieces);
}

static int	consider(int *pieces, char **map, int map_size, long double map_placement)
{
	
}

static int	solve(int *pieces, char **map, int map_size, long double map_placement)
{
	//call consider on first piece
	//if fails, remove piece from map, and place piece in next available spot.
	int found;
	int place_here;

	found = 0;
	while (!found)
	{
		found = consider(pieces, map, map_size, map_placement);
		
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	int			pc;
	int			map_size;
	int			*pieces;
	char		*map;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(pieces = get_validated_pieces(fd)))
		{
			ft_putendl("error");
			return (1);
		}
		pc = 0;
		while (pieces[pc])
			pc++;
		map_size = 2;
		while (map_size * map_size < pc * 4 && !(solve(pieces, &map, map_size, 0)))
			map_size++;
		ft_putstr(map);
		return (0);
	}
	ft_putendl("error");
	return (1);
}
