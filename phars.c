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
	int		i;

	i = 0;

}

int		search_start(char *inp, t_lem *st)
{
	int		i;

	i = 0;

}

int 	valid_line(char *line)
{
	int 	a;

	a = 0;
	if (line[0] == '#')
		return (ft_strstr(line, "##start") ? 1 :
			(ft_strstr(line, "##end") ? 2 : 3));
	while (line[a] != ' ' && line[a] != '\n' && line[a] != '\0')
		a++;
	if (line[a] == ' ')
		a++;
	else
		return(0);
	while (line[a] >= 0 && line[a] <= 9)
		a++;
	if (line[a] == ' ')
		a++;
	else if (ft_printf("ERROR\n"))
		exit (1);
	while (line[a] >= 0 && line[a] <= 9)
		a++;
	if (line[a] == '\0')
		a++;
	else
		return(1);
	return (3);
}

int 	save_room(char *inp, t_lem *st)
{
	static int		i = 0;
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
	if (line[i] != '-' && ft_printf("ERROR\n"))
		exit (1);
	if (line[i + 1] == '\0' && ft_printf("ERROR\n"))
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
		else if (ft_printf("ERROR\n"))
			exit(1);
	inp2 = (char *)malloc(sizeof(inp) * ft_strlen(&line[++i]) + 1);
	inp2 = ft_strcpy(inp2, &line[i]);
	while (ft_strcmp(inp2, tmp2->name))
		if (tmp2->next != NULL)
			tmp2 = tmp2->next;
		else if (ft_printf("ERROR\n"))
			exit(1);

	return (1);
}

int 	phars(t_lem *st)
{
	int 	a;
	int 	b;
	char	*inp;

	while (get_next_line(0, &inp))
	{
		a = 0;
		if ((b = valid_line(&inp[a])) > 0 || save_connect(st, inp))
			if (b == 1)
				search_start(inp, st);
			else if (b == 2)
				search_end(inp, st);
			else if (b == 3)
				continue ;
			else
				save_room(inp, st);
		else
			break ;
		free(inp);
	}
	save_connect(st, inp);
}