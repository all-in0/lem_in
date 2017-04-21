/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:23:44 by vnakonec          #+#    #+#             */
/*   Updated: 2017/04/19 15:23:47 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_room	*search_rr(t_lem *st, int a)
{
	t_room		*room;

	room = st->rooms;
	while (room->rom != a)
		room = room->next;
	return (room);
}

void 	*recurs(t_lem *st, int a, char *str)
{
	char			*s;
	int				i;
	t_room			*room;

	room = search_rr(st, a);
	i = -1;
	while (room->connect[++i] != 0 && i <= int_len(room->connect)) // count connection
	{
		recurs(st, room->connect[i], ft_strjoin_symb(str, a - '0'));
	}
	if (a == -2)
	{
		st->ways = ft_add_str(st->ways, str);
	}
}