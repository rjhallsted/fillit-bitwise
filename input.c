/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:02:51 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/18 14:57:17 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/inc/libft.h"
#include "fillit.h"

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

static int		shift_piece(t_piece *piece, int mask, int shift_by)
{
	int tmp_val;
	int count;

	tmp_val = piece->shape;
	while ((tmp_val & mask) == 0)
		tmp_val = tmp_val >> shift_by;
	piece->shape = tmp_val;
	count = 0;
	while ((tmp_val & mask) != 0)
	{
		tmp_val = tmp_val >> shift_by;
		count++;
	}
	return (count);
}

static void		init_piece(t_piece *piece, char *input, int file_loc, char id)
{
	init_shape(piece, input, file_loc);
	piece->height = shift_piece(piece, 0xf, 4);
	piece->width = shift_piece(piece, 0x1111, 1);
	piece->id = id;
	piece->position = -1;
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
		init_piece(pieces[i], input, file_loc, i + 'A');
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
	char	buff[BUFF_SIZE + 1];
	int		rv;
	int		prog;

	prog = 0;
	while ((rv = read(fd, buff + prog, BUFF_SIZE - prog)) && rv != -1)
		prog += rv;
	buff[prog] = '\0';
	if (rv == -1 || !(input = ft_strdup(buff)))
		return (NULL);
	if (!(validate_input(input)))
		return (NULL);
	if (!(pieces = build_pieces(input)))
		return (NULL);
	free(input);
	return (pieces);
}
