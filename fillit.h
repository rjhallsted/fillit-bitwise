/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:35:15 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/30 13:32:22 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>

# define ERROR_RETURN(i) ft_putendl("Error"); return (i)

enum
{
	PASS,
	ARG_ISSUE,
	INPUT_ISSUE,
	SOLVE_ISSUE
};

typedef struct	s_piece
{
	int			shape;
	size_t		width;
	size_t		height;
}				t_piece;

t_pieces		*get_pieces(int fd);
int				validate_input(int fd);
char			*solve(t_piece *pieces);


#endif
