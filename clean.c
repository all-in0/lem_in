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
	int		i;
	s_way	tmp1;
	s_way	tmp_1;
	t_room	tmp2;

	while (rr->wa != NULL)
	{
		tmp1 = rr->wa;
		while (tmp1->next != NULL) {
			tmp1 = tmp->next;
		}
		free(tmp1->wa);
		free(tmp1);
	}
}