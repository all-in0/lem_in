/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:27:25 by vnakonec          #+#    #+#             */
/*   Updated: 2017/04/04 15:27:26 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(int argc, char **argv)
{
	t_room	*rommmm;
	t_lem	stru;
	char	*inp;
	int		i;
	int 	*mas;

	i = 0;
	__builtin_bzero(&stru, sizeof(t_lem));
	rommmm = (t_room *)malloc(sizeof(t_room));
	__builtin_bzero(rommmm, sizeof(t_room));
	stru.rooms = rommmm;
	get_next_line(0, &inp);
	stru.ants = ft_atoi(inp);
	while (inp[i] <= '9' && inp[i] >= '0')
		i++;
	parsing(&stru);
	ft_printf("%i, %s, $i", stru.rooms->rom, stru.rooms->name, stru.rooms->connect[0]);
	__builtin_bzero(mas = (int *)malloc(sizeof(int *) * 1), sizeof(int *));
	clean_connect(rommmm);
	m_l(&stru);
	recurs(&stru, -1, mas, -1);
	clean_doubles(&stru);
	search_way(&stru);
	return (0);
}