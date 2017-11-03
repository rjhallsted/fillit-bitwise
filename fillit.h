/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:35:15 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/02 20:30:53 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>

# define ERROR_RETURN(i) { ft_putendl("Error"); return (i); }
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
}				t_piece;

t_piece			**get_pieces(int fd);
int				validate_input(char *input);
char			*solve(t_piece *pieces);


#endif
