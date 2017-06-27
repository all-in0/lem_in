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

#include "lem_in.h"

int		g_count = 0;

int		int_len(int *mas)
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

int		*ft_intjoin(int *str, int a)
{
	int		i;
	int		*s;

	i = 0;
	while (str[i] != 0)
		i++;
	s = (int *)malloc(sizeof(int) * (i + 2));
	s[i + 1] = 0;
	s[i] = a;
	while (--i >= 0)
		s[i] = str[i];
	return (s);
}

int		test_repeat(int *mas, int a)
{
	int		i;

	i = 0;
	while (mas[i] != 0 && mas[i] != a)
		i++;
	if (mas[i] == 0)
		return (1);
	return (0);
}

void	recurs(t_lem *st, int a, int *str, int i)
{
	t_room	*room;
	int		*tst;

	if (g_count > 2000)
		return ;
	room = search_rr(st, a);
	st->ptr = save_ptr(str, st->ptr);
	while (g_count <= 2000 && room-> connect != NULL && room->connect[++i] != 0
		&& i <= int_len(room->connect) && a != -2)
	{
		if (room->connect[i] != -1 && test_repeat(str, room->connect[i]))
		{
			tst = ft_intjoin(str, a);
			st->ptr = save_ptr(tst, st->ptr);
			recurs(st, room->connect[i], tst, -1);
		}
	}
	if (a == -2)
	{
		tst = ft_intjoin(str, -2);
		st->ptr = save_ptr(tst, st->ptr);
		st->ways = ft_add_str(st->ways, tst);
		g_count++;
	}
	//free(str);
}
