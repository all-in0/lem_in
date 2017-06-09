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

void	prnt_all(t_way *rr)
{
	while (rr != NULL)
	{
		__builtin_printf("%s\n", rr->wa);
		rr = rr->next;
	}
}

int		main(int argc, char **argv)
{
	//t_way	*wai;
	t_room	*rommmm;
	t_lem	stru;
	char	*inp;
	int		i;
	int 	*mas;

	i = 0;
	__builtin_bzero(&stru, sizeof(t_lem));
	rommmm = (t_room *)malloc(sizeof(t_room));
	__builtin_bzero(rommmm, sizeof(t_room));
//	wai = (t_way *)malloc(sizeof(t_way));
//	__builtin_bzero(wai, sizeof(t_way));
//	wai->wa = NULL;
//	stru.wa = wai;
	stru.rooms = rommmm;
	get_next_line(0, &inp);
	stru.ants = ft_atoi(inp);
	//free(inp);
	//inp = NULL;
	while (inp[i] <= '9' && inp[i] >= '0')
		i++;
	if (inp[i] != '\0' && ft_printf("ERROR\n"))
		exit (0);
	free(inp);
	parsing(&stru);
	//ft_printf("%i, %s", stru.rooms->rom, stru.rooms->name);
	mas = (int *)malloc(sizeof(int));
	mas[0] = 0;
	//__builtin_bzero(mas, sizeof(int));
	clean_connect(stru.rooms);
	recurs(&stru, -1, mas, -1, 1);
	m_l(&stru);
	clean_doubles(&stru);
	search_way(&stru);
	prnt_all(stru.wa);
	cl_all(&stru);
	//free(mas);
	//while (1);
	return (0);
}