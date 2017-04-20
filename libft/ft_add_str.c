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

int 	m_len(char **m)
{
	int		i;

	i = 0;
	while (m[i] != NULL)
	{
		i++;
	}
	return (i + 1);
}

char	**ft_add_str(char **m, char str)
{
	char	**new_m;
	int		i;

	i = -1;
	new_m = (char **)malloc(sizeof(new_m) * (m_len(m) + 1));
	while (m[++i] != NULL)
		new_m[i] = m[i];
	new_m[i] = str;
	new_m[++i] = NULL;
	free(m);
	return (new_m);
}