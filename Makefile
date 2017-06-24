# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/03 15:56:35 by vnakonec          #+#    #+#              #
#    Updated: 2017/06/19 16:28:13 by vnakonec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -Wall -Wextra -Werror

INCLUDES = .

SRCS = lem_in.c\
	  clean_struct.c\
	  clean.c\
	  phars_2.c\
	  pharsing.c\
	  recurs.c\
	  search_ways.c\

OBJ = $(SRCS:.c=.o)

LIBFTDIR = libft/

all: $(NAME)

$(NAME) : $(LIBFTDIR)libftprintf.a $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lftprintf

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

$(LIBFTDIR)libftprintf.a: libft/Makefile
	make -C libft/

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFTDIR)libftprintf.a

re: fclean all
