/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:27:25 by vnakonec          #+#    #+#             */
/*   Updated: 2017/06/19 19:52:18 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

char	*ret_name(int i, t_room *rm)
{
	t_room		*rr;

	rr = rm;
	while (rr->rom != i)
	{
		rr = rr->next;
	}
	return (rr->name);
}

void	ft_print_ints(t_lem *rr)
{
	int		i;
	int 	b;

	i = -1;
	__builtin_printf("The %d ways was used:\n", rr->way);
	while ((rr->way - 1) >= ++i)
	{
		b = 0;
		__builtin_printf("The %d way: ", (i + 1));
		while (rr->ways[i][++b] != 0)
			if (b == 1)
				__builtin_printf("%s->%s", rr->start, ret_name(rr->ways[i][b], rr->rooms));
			else
				__builtin_printf("->%s", ret_name(rr->ways[i][b], rr->rooms));
		__builtin_printf("\n");
	}
	__builtin_printf("\n");
}

void	prnt_all(t_way *rr, t_lem *tl)
{
	int		i;

	i = 0;
	if (tl->way > 0)
		ft_print_ints(tl);
	while (rr != NULL)
	{
		__builtin_printf("%s\n", rr->wa);
		rr = rr->next;
		i++;
	}
	if (tl->move == 1)
		__builtin_printf("\n\x1b[31mThere was %d moves\n", i);
	__builtin_printf("\x1b[0m");

}

void	ants(t_lem *stru)
{
	char	*inp;
	int		i;

	i = 0;
	if (get_next_line(0, &inp) > 0)
		stru->ants = ft_atoi(inp);
	else if (__builtin_printf("ERROR9"))
		exit(1);
	while (inp[i] <= '9' && inp[i] >= '0')
		i++;
	if (inp[i] != '\0' && __builtin_printf("ERROR8\n"))
		exit(0);
	__builtin_printf("\n%s\n", inp);
	free(inp);
}

void	test_all(t_lem *stru)
{
	if ((stru->start == NULL || stru->end == NULL)
		&& __builtin_printf("ERROR7\n"))
		exit(1);
}

int		main(void)
{
	t_room	*rommmm;
	t_lem	stru;
	int		*mas;

	__builtin_bzero(&stru, sizeof(t_lem));
	rommmm = (t_room *)malloc(sizeof(t_room));
	__builtin_bzero(rommmm, sizeof(t_room));
	stru.rooms = rommmm;
	ants(&stru);
	parsing(&stru);
	test_all(&stru);
	mas = (int *)malloc(sizeof(int));
	mas[0] = 0;
	clean_connect(stru.rooms);
	recurs(&stru, -1, mas, -1);
	m_l(&stru);
	clean_doubles(&stru);
	search_way(&stru);
	prnt_all(stru.wa, &stru);
	cl_all(&stru);
	return (0);
}
