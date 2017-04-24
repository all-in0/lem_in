/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:37:15 by vnakonec          #+#    #+#             */
/*   Updated: 2017/04/04 15:37:18 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		search_end(char *inp, t_lem *st)
{
	static int		a = 1;
	int				i;
	t_room			*end;

	if (a == 0 && ft_printf("ERROR5\n"))
		exit (0);
	i = 0;
	while (inp[i] != ' ')
		i++;
	st->end = ft_strnew(i + 1);
	st->end = ft_strncpy(st->end, inp, i);
	end = (t_room *)malloc(sizeof(end));
	__builtin_bzero(end, sizeof(end));
	end->name = st->end;
	end->rom = -2;
	end->next = st->rooms;
	st->rooms = end;
	a = 2;
	return 1;
}

int		search_start(char *inp, t_lem *st)
{
	static int		a = 1;
	int				i;
	t_room			*start;

	if (a == 0 && ft_printf("ERROR6\n"))
		exit (1);
	i = 0;
	while (inp[i] != ' ')
		i++;
	st->start = ft_strnew(i + 1);
	st->start = ft_strncpy(st->start, inp, i);
	start = (t_room *)malloc(sizeof(start));
	__builtin_bzero(start, sizeof(start));
	start->name = st->start;
	start->rom = 1;
	start->next = st->rooms;
	st->rooms = start;
	a = 0;
	return 1;
}

int 	valid_line(char *line)
{
	int 	a;

	a = 0;
	if (line[0] == '#')
		return (ft_strstr(line, "##start") ? 1 :
			(ft_strstr(line, "##end") ? 2 : 3));
	while (line[a] != ' ' && line[a] != '\0')
		a++;
	if (line[a] == ' ' && a > 0)
		a++;
	else
		return(0);
	while (line[a] >= '0' && line[a] <= '9')
		a++;
	if (line[a] == ' ' && (line[a - 1] >= '0' && line[a - 1] <= '9'))
		a++;
	else
		return (0);
	while (line[a] >= '0' && line[a] <= '9')
		a++;
	if (line[a] == '\0' && (line[a - 1] >= '0' && line[a - 1] <= '9'))
		return(4);
	return (0);
}

int 	save_room(char *inp, t_lem *st)
{
	static int		i = 1;
	t_room	*r;
	t_room	*new;
	int		a;

	a = 0;
	i++;
	r = st->rooms;
	new = (t_room *)malloc(sizeof(new));
	while (r->rom != i - 1)
		r = r->next;
	__builtin_bzero(new, sizeof(new));
	r->next = new;
	r = r->next;
	r->rom = i;
	while (inp[a] != ' ')
		a++;
	r->name = (char *)malloc(sizeof(r->name) * a);
	r->name[a] = '\0';
	while (a-- != -1)
		r->name[a] = inp[a];
	return (0);
}

int 	test_conect(char *line)
{
	int 	i;

	i = 0;
	while (line[i] != '-' && line[i] != '\0')
		i++;
	if (line[i] != '-' && ft_printf("ERROR7\n"))
		exit (1);
	if (line[i + 1] == '\0' && ft_printf("ERROR8\n"))
		exit (1);
	return (1);
}

int 	save_connect(t_lem *st, char *line)
{
	char 	*inp;
	char 	*inp2;
	int 	i;
	t_room	*tmp;
	t_room	*tmp2;

	tmp = st->rooms;
	tmp2 = st->rooms;
	i = 0;
	test_conect(line);
	while (line[i] != '-')
		i++;
	inp = (char *)malloc(sizeof(inp) * i + 1);
	inp = ft_strncpy(inp, line, i);
	while (ft_strcmp(inp, tmp->name))
		if (tmp->next != NULL)
			tmp = tmp->next;
		else if (ft_printf("ERROR9\n"))
			exit(1);
	tmp->name = inp;
	inp2 = (char *)malloc(sizeof(inp) * ft_strlen(&line[++i]) + 1);
	inp2 = ft_strcpy(inp2, &line[i]);
	while (ft_strcmp(inp2, tmp2->name))
		if (tmp2->next != NULL)
			tmp2 = tmp2->next;
		else if (ft_printf("ERROR1\n"))
			exit(1);
	tmp2->name = inp2;
	return (1);
}

int 	parsing(t_lem *st)
{
	int 	b;
	char	*inp;

	while (get_next_line(0, &inp))
	{
		if ((st->rooms == NULL && (b = valid_line(inp)) > 0) ||
			save_connect(st, inp))
			if (b == 1)
				get_next_line(0, &inp) ? ((valid_line(inp) == 4) ? search_start(inp, st) : exit (1)) : exit (1);
			else if (b == 2)
				!get_next_line(0, &inp) ? exit (1) :
				valid_line(inp) == 4 ? search_end(inp, st) : exit (1);
			else if (b == 3)
				continue ;
			else
				save_room(inp, st);
		else
			break ;
		free(inp);
	}
	return (1);
}