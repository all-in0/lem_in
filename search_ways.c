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

#include "lem_in.h"

void		save_w2(t_way *tw, char *in, const char *str)
{
	char		*tmp;
	char		*tmp2;
	char		*tmp3;
	char		*tmp4;
	char		*tm;

	tm = tw->wa;
	tmp3 = ft_strjoin("\x1b[33mL", in);
	tmp4 = ft_strjoin("\x1b[0m-\x1b[36m", str);
	tmp2 = ft_strjoin(tmp3, tmp4);
	tmp = ft_strjoin("\x1b[0m ", tmp2);
	tw->wa = ft_strjoin(tw->wa, tmp);
	free(tmp);
	free(tmp2);
	free(tmp3);
	free(tmp4);
	free(tm);
}

void		save_wa(int a, int b, t_way *tw, t_lem *rr)
{
	const char	*str;
	char		*in;
	char		*tmp;
	char		*tmp2;

	in = ft_itoa(a);
	str = search_rr(rr, b)->name;
	if (tw->wa == NULL)
	{
		tmp = ft_strjoin("\x1b[33mL", in);
		tmp2 = ft_strjoin("\x1b[0m-\x1b[36m", str);
		tw->wa = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	else
		save_w2(tw, in, str);
	free(in);
}

t_way		*sea_2(t_lem *rr)
{
	t_way	*tw;

	tw = (t_way *)malloc(sizeof(t_way));
	tw->wa = NULL;
	tw->next = NULL;
	tw->day = 1;
	rr->wa = tw;
	return (tw);
}

void		sea_w(t_lem *rr, int a, int i, int b)
{
	t_way	*tw;
	int		w;

	w = 0;
	if (rr->wa == NULL)
		tw = sea_2(rr);
	else
		tw = rr->wa;
	while (rr->ways[i][++w] != 0)
	{
		while (tw->next != NULL)
			if (tw->day == b)
				break ;
			else
				tw = tw->next;
		if (tw->next == NULL && tw->day != b)
		{
			tw->next = (t_way *)malloc(sizeof(t_way));
			sea_3(tw, b);
			tw = tw->next;
		}
		save_wa(a, rr->ways[i][w], tw, rr);
		b++;
	}
}

int			search_way(t_lem *rr)
{
	int		a;
	int		b;
	int		i;

	a = 0;
	i = 0;
	b = 1;
	while (++a <= rr->ants)
	{
		if (rr->way > 0 && rr->way < i)
			rr->way = i;
		if (rr->ways[i] != 0)
			sea_w(rr, a, i, b);
		else
			a--;
		if (((rr->ways[i] == 0 || ((rr->ways[i][0] - 2 - i) >
			(rr->ants - a))) || rr->ways[1] == 0))
		{
			b++;
			i = 0;
		}
		else
			i++;
	}
	return (1);
}
