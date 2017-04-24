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
	t_room	rommmm;
	t_lem	stru;
	char	*inp;
	int		i;

	i = 0;
	__builtin_bzero(&stru, sizeof(stru));
	__builtin_bzero(&rommmm, sizeof(rommmm));
	stru.rooms = &rommmm;
	get_next_line(0, &inp);
	stru.ants = ft_atoi(inp);
	while (inp[i] <= '9' && inp[i] >= '0')
		i++;
	parsing(&stru);
	ft_printf("%i, %s, $i", stru.rooms->rom, stru.rooms->name, stru.rooms->connect[0]);
//	recurs(&stru, 1, NULL);
	return (0);
}