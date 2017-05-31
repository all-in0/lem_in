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

#include "lem-in.h"

int 	cl_all(t_lem *rr)
{
	int 	i;
	t_way	*tmp;
	t_room	*tm;

	i = -1;
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
	while (rr->ways[++i] != 0)
		free(rr->ways[i]);
	free(rr->ways[i]);
	free(rr->ways);
//	free(rr->start);
//	free(rr->end);
	return(0);
}