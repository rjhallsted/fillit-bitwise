/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:05:18 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/23 21:51:21 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_map
{
	long double	placement;
	char		*printable;
	int			size;
}				t_map;

typedef struct	s_piece
{
	int			shape;
	int			width;
	int			height;
}				t_piece;

#endif
