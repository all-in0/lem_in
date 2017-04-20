/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:46:56 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 15:51:18 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		color(const char *s)
{
	int		i;

	i = 0;
	if (s[1] == 'r' && s[2] == 'e' && s[3] == 'd' && s[4] == '}' && ++i > 0)
		RED;
	else if (s[1] == 'g' && s[2] == 'r' && s[3] == 'e' &&
		s[4] == '}' && ++i > 0)
		GRE;
	else if (s[1] == 'y' && s[2] == 'e' && s[3] == 'l' &&
		s[4] == '}' && ++i > 0)
		YEL;
	else if (s[1] == 'b' && s[2] == 'l' && s[3] == 'u' &&
		s[4] == '}' && ++i > 0)
		BLU;
	else if (s[1] == 'm' && s[2] == 'a' && s[3] == 'g' &&
		s[4] == '}' && ++i > 0)
		MAG;
	else if (s[1] == 'c' && s[2] == 'y' && s[3] == 'a' &&
		s[4] == '}' && ++i > 0)
		CYA;
	else if (s[1] == 'e' && s[2] == 'o' && s[3] == 'c' &&
		s[4] == '}' && ++i > 0)
		EOC;
	return (i > 0 ? 5 : 0);
}
