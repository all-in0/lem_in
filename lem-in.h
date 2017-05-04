/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:27:44 by vnakonec          #+#    #+#             */
/*   Updated: 2017/04/04 15:27:46 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/ft_printf.h"

typedef struct		s_room
{
	int 			rom;
	char 			*name;
	int				*connect; // ne nugno pisat' start!
	int 			count;
	struct s_room	*next;
}					t_room;

typedef struct		s_lem
{
	int 			rm;
	int 			*con;
	int				**ways;
	int				ants;
	char			*start;
	char 			*end;
	t_room			*rooms;
}					t_lem;

void 	recurs(t_lem *st, int a, int *str);
int 	parsing(t_lem *str);

#endif