/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:35:15 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/27 15:05:58 by rhallste         ###   ########.fr       */
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

t_piece			**build_valid_pieces(int fd);
char			*solve(t_piece *pieces);


#endif
