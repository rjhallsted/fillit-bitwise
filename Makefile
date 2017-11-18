# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 09:37:14 by rhallste          #+#    #+#              #
#    Updated: 2017/11/18 14:35:32 by rhallste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	fillit
LIBNAME		=	libft/libft.a

TESTFILE	=	valid11

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

MAINLIST	=	validate_input			\
				input					\
				main					\
				backtracking			\
				solve

MAINSRCS	=	$(addsuffix .c, $(MAINLIST))
MAINOBJS	=	$(addsuffix .o, $(MAINLIST))

all: $(NAME)

$(MAINOBJS): $(MAINSRCS)

$(LIBNAME):
	make -C libft

$(NAME): $(LIBNAME) $(MAINOBJS)
	$(CC) $(CFLAGS) $(MAINOBJS) $(LIBNAME) -o $(NAME)

clean:
	@rm -rf $(MAINOBJS) $(TESTOBJS)

fclean: clean
	@rm -rf $(NAME) $(LIBNAME) t

re: fclean all

.SILENT: $(MAINOBJS)
