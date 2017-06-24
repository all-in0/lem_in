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

#include "lem_in.h"

void	cleanc(int *mas, int a)
{
	int		i;
	int		b;

	i = -1;
	while (mas[++i] != 0)
	{
		if (mas[i] == a)
		{
			b = i;
			while (mas[b] != 0)
			{
				mas[b] = mas[b + 1];
				b++;
			}
		}
	}
}

void	clean_connect(t_room *rr)
{
	t_room	*rm;
	int		i;

	rm = rr;
	while (rm != NULL)
	{
		i = -1;
		while (rm->connect != NULL && rm->connect[++i] != 0)
			cleanc(&rm->connect[i + 1], rm->connect[i]);
		rm = rm->next;
	}
}

int		del_row(t_lem *rr, int b)
{
	while (rr->ways[b] != 0)
	{
		rr->ways[b] = rr->ways[b + 1];
		b++;
	}
	free(rr->ways[b]);
	return (1);
}

void	ft_cl_d(t_lem *rr, int a, int i)
{
	int		b;
	int		c;

	b = a;
	while (rr->ways[++b] != 0)
	{
		c = 0;
		while (rr->ways[b][++c] != 0)
		{
			if (rr->ways[b][c] == rr->ways[a][i])
				if (del_row(rr, b--))
					break ;
		}
	}
}

void	clean_doubles(t_lem *rr)
{
	int		i;
	int		b;

	i = -1;
	while (rr->ways[++i] != 0)
	{
		b = 0;
		while (rr->ways[i][++b])
			if (rr->ways[i][b] > 0)
				ft_cl_d(rr, i, b);
	}
}
