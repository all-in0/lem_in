/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:24:17 by vnakonec          #+#    #+#             */
/*   Updated: 2017/05/12 17:24:20 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int 	search_way(t_lem *rr)
{
	t_room	*rw;
	int 	a;
	int 	i;

	while (rr->ants)
	{
		rw = rr->rm;
		while (!rw->rom)
			rw = rw->next;
		rr->ants--;
	}
//	while(ants)
//	{
//		if (way[i][0] <= ants)
//			ants--;
//		write way_name (way[i][1]++);
//	}
}