/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:02:51 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/03 13:44:19 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/inc/libft.h"
#include "fillit.h"

static char		*read_file(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		rv;
	int		prog;

	prog = 0;
	while ((rv = read(fd, buff + prog, BUFF_SIZE - prog)) && rv != -1)
		prog += rv;
	buff[prog] = '\0';
	return ((rv != -1) ? ft_strdup(buff) : NULL);
}

static void		init_shape(t_piece *piece, char *input, int file_loc)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 != 4)
		{
			piece->shape = piece->shape << 1;
			piece->shape += (*(input + file_loc + i) == '#') ? 1 : 0;
		}
		i++;
	}
}

/*
** WORKING ON THIS FUNCTION BELOW
*/

static void		trim_shape_rows(t_piece *piece)
{
	int tmp_val;
	int count;

	tmp_val = piece->shape;
	while (((tmp_val >> 4) ^ 0xfff0) == 0)
		tmp_val = tmp_val >> 4;
	piece->shape = tmp_val;
	count = 1;
	while (((tmp_val >> 4) ^ 0xfff0) != 0)
	{
		tmp_val = tmp_val >> 4;
		count++;
	}
	piece->height = count;
}

static void		init_piece(t_piece *piece, char *input, int file_loc)
{
	init_shape(piece, input, file_loc);
	trim_shape_rows(piece);
}

static t_piece	**build_pieces(char *input)
{
	int			i;
	int			pc;
	int			file_loc;
	t_piece		**pieces;

	pc = (ft_strlen(input) / 21) + 1;
	if (!(pieces = ft_memalloc((sizeof(t_piece *) * (pc + 1)))))
		return (NULL);
	i = 0;
	file_loc = 0;
	while (i < pc)
	{
		if (!(pieces[i] = ft_memalloc(sizeof(t_piece))))
		{
			ft_free_2d_array((void ***)&pieces, i);
			return (NULL);
		}
		init_piece(pieces[i], input, file_loc);
		file_loc += 21;
		i++;
	}
	pieces[i] = NULL;
	return (pieces);
}

t_piece			**get_pieces(int fd)
{
	char	*input;
	t_piece	**pieces;

	if (!(input = read_file(fd)))
		return (NULL);
	if (!(validate_input(input)))
		return (NULL);
	if (!(pieces = build_pieces(input)))
		return (NULL);
	free(input);
	return (pieces);
}
