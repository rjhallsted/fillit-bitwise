/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 11:43:30 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/30 13:24:48 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

static int	count_connections(char *piece, int index)
{
	int count;

	count = 0;
	if (index % 5 != 0)
		if (piece[index - 1] == '#')
			count++;
	if (index % 5 != 3)
		if (piece[index + 1] == '#')
			count++;
	if (index > 4)
		if (piece[index - 5] == '#')
			count++;
	if (index < 14)
		if (piece[index + 5] == '#')
			count++;
	return (count);
}

static int	check_piece(char *piece)
{
	int i;
	int connections;
	int	piece_count;

	if (!piece)
		return (0);
	i = -1;
	connections = 0;
	piece_count = 0;
	while (++i < 20)
		if (i % 5 == 4 && piece[i] != '\n')
			return (0);
		else if (i % 5 != 4)
		{
			if (piece[i] != '.' && piece[i] != '#')
				return (0);
			if (piece[i] == '#')
			{
				connections += count_connections(piece, i);
				piece_count++;
			}
		}
	if (piece_count != 4 || (connections != 6 && connections != 8))
		return (0);
	return (1);
}

int			validate_input(char *input)
{
	int		input_len;
	int		i;
	char	*piece;

	input_len = ft_strlen(input);
	if (input_len < 20)
		return (0);
	i = 0;
	while (i < input_len)
	{
		piece = ft_strsub(input, i, 20);
		if (!(check_piece(piece)))
			return (0);
		free(piece);
		i += 20;
		if (i < input_len && input[i] != '\n')
			return (0);
		if (input_len - i < 20 && input_len - i > 0)
			return (0);
		i++;
	}
	return (1);
}
