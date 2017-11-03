/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:32:01 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/02 20:19:01 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/inc/libft.h"
#include "fillit.h"

#include <stdio.h>

char	*binary_to_string(int piece)
{
	char *str;
	int i;
	
	i = 0;
	str = ft_memalloc(17);
	while (i < 16)
	{
		str[i] = ((piece >> 15) - i == 1) ? '#' : '.';
		i++;
	}
	return (str);
}

void	print_them(t_piece *pieces)
{
	while (pieces)
	{
		printf("%s\n", binary_to_string((*pieces).shape));
		pieces++;
	}
}

int main(int argc, char **argv)
{
	int		fd;
	t_piece	*pieces;
//	char	*map;

	if (argc == 2)
	{
		printf("in main\n");
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ERROR_RETURN(ARG_ISSUE)
		printf("opened file\n");
		if (!(pieces = get_pieces(fd)))
			ERROR_RETURN(INPUT_ISSUE)
		printf("got_pieces\n");
		/* if (!(map = solve(pieces))) */
		/* 	ERROR_RETURN(SOLVE_ISSUE); */
		/* ft_putstr(map); */
		print_them(pieces);
		return (PASS);
	}
	else
		ERROR_RETURN(ARG_ISSUE)
}
