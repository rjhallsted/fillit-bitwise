/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:35:15 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/18 14:42:33 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>

# define ERROR_RETURN(i) { ft_putendl("error"); return (i); }
# define BUFF_SIZE 545

enum
{
	PASS = 0,
	ARG_ISSUE = 1,
	INPUT_ISSUE = 2,
	SOLVE_ISSUE = 3
};

typedef struct	s_piece
{
	int			shape;
	size_t		width;
	size_t		height;
	char		id;
	int			position;
}				t_piece;

typedef struct	s_map
{
	int			size;
	long long	placement;
}				t_map;

t_piece			**get_pieces(int fd);
long long		modify_shape_to(t_piece *piece, int map_size, int pos);
int				validate_input(char *input);
int				try(t_piece **pieces, t_map *map);
char			*solve(t_piece **pieces);


#endif
