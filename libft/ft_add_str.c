/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:13:29 by vnakonec          #+#    #+#             */
/*   Updated: 2017/04/20 15:13:34 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		m_len(int **m)
{
	int		i;

	i = 0;
	while (m[i] != 0)
	{
		i++;
	}
	return (i + 1);
}

int		**ft_add_str(int **m, int *str)
{
	int		**new_m;
	int		i;

	i = -1;
	if (m == NULL)
	{
		m = (int **)malloc(sizeof(new_m) * 1);
		m[0] = 0;
	}
	new_m = (int **)malloc(sizeof(str) * (m_len(m) + 1));
	while (m[++i] != 0)
		new_m[i] = m[i];
	new_m[i] = str;
	new_m[++i] = 0;
	free(m);
	return (new_m);
}
