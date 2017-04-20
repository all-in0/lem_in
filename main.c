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
	t_lem	*stru;
	char	*inp;
	int		i;

	i = 0;
	stru = (t_lem *)malloc(sizeof(stru));
	__builtin_bzero(&stru, sizeof(stru));
	get_next_line(0, &inp);
	stru->ants = ft_atoi(inp);
	while (inp[i] <= 9 && inp >= 0)
		i++;
	if (inp[i] != '\0')
	{
		write (1, "ERROR", 5);
		return (0);
	}
	phars(stru);
	recurs(stru, 1, NULL);
	return (0);
}