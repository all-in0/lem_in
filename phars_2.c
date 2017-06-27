/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phars_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 19:01:38 by vnakonec          #+#    #+#             */
/*   Updated: 2017/06/13 19:01:40 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*save_connn_2(t_lem *st, char *line, int i)
{
	char		*inp2;
	t_room		*tmp2;

	tmp2 = st->rooms;
	inp2 = (char *)malloc(sizeof(char) * (ft_strlen(&line[++i]) + 1));
	inp2 = ft_strcpy(inp2, &line[i]);
	while (ft_strcmp(inp2, tmp2->name))
		if (tmp2->next != NULL)
			tmp2 = tmp2->next;
		else if (ft_printf("ERROR\n"))
			exit(1);
	free(inp2);
	return (tmp2);
}

int			search_end(char *inp, t_lem *st)
{
	static int		a = 1;
	int				i;
	t_room			*end;

	if (a == 2 && ft_printf("ERROR\n"))
		exit(0);
	i = 0;
	while (inp[i] != ' ')
		i++;
	st->end = ft_strnew(i + 1);
	st->end = ft_strncpy(st->end, inp, i);
	end = (t_room *)malloc(sizeof(t_room));
	end->connect = NULL;
	end->name = st->end;
	end->rom = -2;
	end->next = st->rooms;
	st->rooms = end;
	a = 2;
	return (1);
}

int			search_start(char *inp, t_lem *sd)
{
	static int		a = 1;
	t_room			*st;
	int				i;

	st = sd->rooms;
	if (a == 0 && ft_printf("ERROR\n"))
		exit(1);
	i = 0;
	while (inp[i] != ' ')
		i++;
	if (st->rom == -2)
		st = st->next;
	sd->start = ft_strnew(i + 1);
	sd->start = ft_strncpy(sd->start, inp, i);
	st->name = sd->start;
	st->rom = -1;
	a = 0;
	return (1);
}

int			save_room(char *inp, t_lem *st)
{
	static int		i = 0;
	t_room			*r;
	t_room			*new;
	int				a;

	a = 0;
	i++;
	r = st->rooms;
	new = (t_room *)malloc(sizeof(t_room));
	while (r->next != NULL)
		r = r->next;
	new->next = NULL;
	new->connect = NULL;
	new->name = NULL;
	r->next = new;
	r = r->next;
	r->rom = i;
	while (inp[a] != ' ')
		a++;
	r->name = (char *)malloc(a + 1);
	r->name[a] = '\0';
	ft_strncpy(r->name, inp, a);
	return (0);
}

int			test_conect(char *line)
{
	int				i;

	i = 0;
	while (line[i] != '-' && line[i] != '\0')
		i++;
	if (line[i] != '-' && ft_printf("ERROR\n"))
		exit(1);
	if (line[i + 1] == '\0' && ft_printf("ERROR\n"))
		exit(1);
	return (1);
}
