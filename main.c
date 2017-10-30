/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:32:01 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/30 13:32:51 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/inc/libft.h"
#include "fillit.h"

int main(int argc, char **argv)
{
	int		fd;
	t_piece	**pieces;
	char	*map;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ERROR_RETURN(ARG_ISSUE);
		if (!(pieces = get_pieces(fd)))
			ERROR_RETURN(INPUT_ISSUE);
		if (!(map = solve(pieces)))
			ERROR_RETURN(SOLVE_ISSUE);
		ft_putstr(map);
		return (PASS);
	}
	else
		ERROR_RETURN(ARG_ISSUE);
}
