/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 16:35:38 by vnakonec          #+#    #+#             */
/*   Updated: 2017/04/28 16:35:40 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_add_int(int *mas, int a)
{
	int		*temp;
	int		i;

	i = 0;
	if (mas != NULL)
		while (mas[i] != 0)
			i++;
	temp = (int *)malloc(sizeof(temp) * (i + 2));
	temp[i + 1] = 0;
	temp[i] = a;
	while (i > 0)
	{
		i--;
		temp[i] = mas[i];
	}
	free(mas);
	return (temp);
}
