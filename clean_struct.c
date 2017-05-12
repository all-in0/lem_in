/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:14:51 by vnakonec          #+#    #+#             */
/*   Updated: 2017/05/03 19:14:52 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	cleanc(int *mas, int a)
{
	int		i;

	i = -1;
	while (mas[++i] != 0)
	{
		if(mas[i] == a)
		{
			while (mas[i] != 0)
			{
				mas[i] = mas[i + 1];
				i++;
			}
			return ;
		}
	}

}

void	clean_connect(t_room *rr)
{
	t_room	*rm;
	int		i;
	int		a;

	rm = rr;
	while (rm != NULL)
	{
		i = -1;
		while (rm->connect[++i] != 0)
			cleanc(&rm->connect[i + 1], rm->connect[i]);
		rm = rm->next;
	}
}

void 	bubble_m(t_lem *st)
{
	int 	*tmp;
	int 	i;

	while (1)
	{
		i = 0;
		while (st->ways[i] != 0)
		{
			if (st->ways[i][0] > st->ways[i + 1][0])
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
	int 	i;
	int 	a;

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

void 	clean_doubles(t_lem *rr)
{
	t_lem	*rm;
	int 	i;
	int 	a;
	int		b;
	int		c;

	rm = rr;
	i = -1;
	while (rm->ways[++i] != 0)
	{
		a = -1;
		while (rm->ways[i][++a] != 0)
		{
			b = i;
			while (rm->ways[b] != 0)
			{
				if (rm->ways[b][c] == 0)
					b++;
				if (rm->ways[i][c] == rm->ways[a][b])
					rm_way(ways, a);
			}
		}
	}
}