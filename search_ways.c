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

#include "lem-in.h"


//int 	search_ways(t_lem *rr)
//{
//	t_way	*w;
//
//	w = rr->wa;
//
//}


// install valgrind

void	*save_wa(int a, int b, t_way *tw, t_lem *rr) {
	char	*str;
	char	*in;
	in = ft_itoa(a);
	str = search_rr(rr, b)->name;
	if (tw->wa == NULL)
		tw->wa = ft_strjoin(ft_strjoin("L", in), ft_strjoin("-", str));
	else
		tw->wa = ft_strjoin(tw->wa, ft_strjoin(" ", ft_strjoin(ft_strjoin("L", in), ft_strjoin("-", str))));
}

int 	sea_w(t_lem *rr, int a, int i, int b)
{
	t_way	*tmpw;
	t_way	*tw;
	int 	w;

	w = 0;
	if (rr->wa == NULL) {
		tw = (t_way *) malloc(sizeof(tw) * 1);
		tw->wa = NULL;
		tw->next = NULL;
		tw->day = 1;
		rr->wa = tw;
	}
	else
		tw = rr->wa;
	while (rr->ways[i][++w] != 0)
	{
		while (tw != NULL && tw->day != b) // correct mistake with checking value
			tw = tw->next;
		if (tw == NULL)
		{
			tw->next = (tmpw = (t_way *) malloc(sizeof(tmpw) * 1));
			tw = tw->next;
			__builtin_bzero(tw, sizeof(tw));
			tw->day = b;
		}
			tw->wa = save_wa(a, rr->ways[i][w], tw, rr);
		b++;
	}
	return 0;
}

int 	search_way(t_lem *rr)
{
	int 	a;
	int 	b;
	int 	i;

	a = 0;
	i = 0;
	b = 1;
	while(++a <= rr->ants)
	{
		if (((rr->ways[i] == 0 || (rr->ways[i][0] > (rr->ants - a))) && (i != 0 && ++b)))
			i = 0;
		else if (rr->ways[i + 1] != 0)
			i++;
		sea_w(rr, a, i, b);
	}
}