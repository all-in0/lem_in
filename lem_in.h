/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:27:44 by vnakonec          #+#    #+#             */
/*   Updated: 2017/06/19 15:34:56 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/ft_printf.h"

typedef struct		s_room
{
	int				rom;
	char			*name;
	int				*connect;
	struct s_room	*next;
}					t_room;

typedef struct		s_way
{
	int				day;
	char			*wa;
	struct s_way	*next;
}					t_way;

typedef struct		s_lem
{
	int 			move;
	int 			way;
	int				rm;
	int				**ways;
	int				ants;
	char			*start;
	char			*end;
	t_way			*wa;
	t_room			*rooms;
}					t_lem;

void				m_l(t_lem *st);
void				sea_3(t_way *tw, int b);
t_room				*save_connn_2(t_lem *st, char *line, int i);
int					save_room(char *inp, t_lem *st);
int					test_conect(char *line);
int					search_start(char *inp, t_lem *st);
int					search_end(char *inp, t_lem *st);
int					cl_all(t_lem *rr);
int					search_way(t_lem *rr);
t_room				*search_rr(t_lem *st, int a);
void				clean_connect(t_room *rr);
void				m_l(t_lem *st);
void				clean_doubles(t_lem *rr);
void				recurs(t_lem *st, int a, int *str, int i);
int					parsing(t_lem *str);

#endif
