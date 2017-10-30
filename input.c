/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:02:51 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/30 14:09:52 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft/inc/libft.h"
#include "fillit.h"

static char		*read_file(int fd)
{
	char	buff[545];
	int		rv;
	int		prog;

	prog = 0;
	while ((rv = read(fd, buff + prog, 545 - prog)) && rv != -1)
		prog += rv;
	return ((rv != -1) ? ft_strdup(buff) : NULL);
}

static void		init_piece(*t_piece piece, char *input, int file_loc)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 != 4)
		{
			piece->shape << 1;
			piece->shape += (*(input + file_loc + i) == '#') ? 1 : 0;
		}
		i++;
	}
}

static t_piece	*build_pieces(char *input)
{
	int			i;
	int			pc;
	int			file_loc;
	t_pieces	*pieces;

	pc = (ft_strlen(input) / 21) + 1;
	if (!(pieces = ft_memalloc((sizeof(t_piece) * pc) + 1)))
		return (NULL);
	i = 0;
	file_loc = 0;
	while (i < pc)
	{
		ft_bzero(pieces[i], sizeof(t_piece));
		init_piece(&(pieces[i]), input, file_loc);
		file_loc += 21;
		i++;
	}
	pieces[i] = NULL;
}

t_pieces		*get_pieces(int fd)
{
	char	*input;
	t_piece	*pieces;

	if (!(input = read_file(fd)))
		return (NULL);
	if (!(validate_input(input)))
		return (NULL);
	if (!(pieces = build_pieces(input)))
		return (NULL);
	free(input);
	return (pieces);
}
