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

int 	int_len(int *mas)
{
	int		i;

	i = 0;
	while (mas[i] != 0)
		i++;
	return (i);
}

t_room	*search_rr(t_lem *st, int a)
{
	t_room		*room;

	room = st->rooms;
	while (room->rom != a)
		room = room->next;
	return (room);
}

int 	*ft_intjoin(int *str, int a)
{
	int		i;
	int 	*s;

	i = 0;
	while (str[i] != 0)
		i++;

}

void 	recurs(t_lem *st, int a, int *str)
{
	int				i;
	t_room			*room;

	room = search_rr(st, a);
	i = -1;
	while (room->connect[++i] != 0 && i <= int_len(room->connect)) // count connection
	{
		recurs(st, room->connect[i], ft_intjoin(str, a));
	}
	if (a == -2)
	{
		st->ways = ft_add_str(st->ways, str);
	}
}