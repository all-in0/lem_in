/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_symb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:45:00 by vnakonec          #+#    #+#             */
/*   Updated: 2017/04/21 18:45:02 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_symb(char *str, char a)
{
	int		i;
	char	*st;

	i = -1;
	st = (char *)malloc(sizeof(st) * ft_strlen(str) + 2);
	while (str[++i] != '\0')
		st[i] = str[i];
	st[i] = a;
	st[++i] = '\0';
	return (st);
}
