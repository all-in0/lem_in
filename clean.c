/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:56:28 by vnakonec          #+#    #+#             */
/*   Updated: 2017/05/24 16:56:32 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	bubble_m(t_lem *st)
{
	int		*tmp;
	int		i;

	while (1)
	{
		i = 0;
		while (st->ways[i] != 0)
		{
			if (st->ways[i + 1] != 0 && st->ways[i][0] > st->ways[i + 1][0])
			{
				tmp = st->ways[i];
				st->ways[i] = st->ways[i + 1];
				st->ways[i + 1] = tmp;
				break ;
			}
			i++;
		}
		if (st->ways[i] == 0)
			return ;
	}
}

void	m_l(t_lem *st)
{
	int		i;
	int		a;

	if (st->ways == NULL && __builtin_printf("ERROR\n"))
		exit(1);
	a = -1;
	while (st->ways[++a] != 0)
	{
		i = 0;
		while (st->ways[a][i] != 0)
			i++;
		st->ways[a][0] = i;
	}
	bubble_m(st);
}

void	sea_3(t_way *tw, int b)
{
	tw->next->wa = NULL;
	tw->next->next = NULL;
	tw->next->day = b;
}

void	free_ptr(t_ptr *rr)
{
	t_ptr	*tmp;
	t_ptr	*prev;

	prev = NULL;
	//rr = rr->next;
	while (rr != NULL)
	{
//		tmp = rr;
//		rr = rr->next;
//		free(tmp->ptr);
//		free(tmp->next);
		//if (rr->ptr[0] != 0)
		free(rr->ptr);
		prev = rr;
		rr = rr->next;
		free(prev);
	}
	//free(prev);
}

int		cl_all(t_lem *rr)
{
	t_way	*tmp;
	t_room	*tm;

	while (rr->wa)
	{
		tmp = rr->wa;
		rr->wa = rr->wa->next;
		free(tmp->wa);
		free(tmp);
	}
	while (rr->rooms)
	{
		tm = rr->rooms;
		rr->rooms = rr->rooms->next;
		free(tm->name);
		free(tm->connect);
		free(tm);
	}
//	while (rr->ways[++i] != 0)
//		free(rr->ways[i]);
//	free(rr->ways[i]);
	//free(rr->ways);
	free_ptr(rr->ptr);
	free(rr->ways);
	return (0);
}
