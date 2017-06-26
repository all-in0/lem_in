/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:01:45 by vnakonec          #+#    #+#             */
/*   Updated: 2017/06/26 18:01:47 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ptr	*save_ptr(int *p, t_ptr *ptr)
{
	t_ptr	*tmp;

	if (ptr == NULL)
	{
		ptr = (t_ptr *)malloc(sizeof(t_ptr));
		ptr->ptr = p;
		ptr->next = NULL;
	}
	else
	{
		tmp = ptr;
		while (tmp->next != NULL) {
			if (tmp->ptr == p)
				return (ptr);
			tmp = tmp->next;
		}
		tmp->next = (t_ptr *)malloc(sizeof(t_ptr));
		tmp->next->next = NULL;
		tmp->next->ptr = p;
	}
	return (ptr);
}