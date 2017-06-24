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

#include "lem_in.h"

int		valid_line_2(char *line, int a)
{
	while (line[a] >= '0' && line[a] <= '9')
		a++;
	if (line[a] == ' ' && (line[a - 1] >= '0' && line[a - 1] <= '9'))
		a++;
	else
		return (0);
	while (line[a] >= '0' && line[a] <= '9')
		a++;
	if (line[a] == '\0' && (line[a - 1] >= '0' && line[a - 1] <= '9'))
		return (4);
	return (0);
}

int		valid_line(char *line, t_lem *st)
{
	int				a;

	a = 0;
	__builtin_printf("%s\n", line);
	if (line[0] == 'L' && __builtin_printf("ERROR\n"))
		exit(0);
	if (line[0] == '#')
	{
		if (!ft_strcmp(line, "##start"))
			return (1);
		else if (!ft_strcmp(line, "##end"))
			return (2);
		else if (!ft_strcmp(line, "##way"))
			st->way = 1;
		else if (!ft_strcmp(line, "##move"))
			st->move = 1;
		return (3);
	}
	while (line[a] != ' ' && line[a] != '\0')
		a++;
	if (line[a] == ' ' && a > 0)
		a++;
	else
		return (0);
	return (valid_line_2(line, a));
}

int		save_connect(t_lem *st, char *line)
{
	char		*inp;
	int			i;
	t_room		*tmp;
	t_room		*tmp2;

	tmp = st->rooms;
	i = 1;
	test_conect(line);
	while (line[i] != '-')
		i++;
	inp = (char *)malloc(sizeof(char) * (i + 1));
	__builtin_bzero(inp, sizeof(char) * (i + 1));
	inp = ft_strncpy(inp, line, i);
	while (ft_strcmp(inp, tmp->name))
		if (tmp->next != NULL)
			tmp = tmp->next;
		else if (__builtin_printf("ERROR3\n"))
			exit(1);
	tmp2 = save_connn_2(st, line, i);
	tmp2->connect = ft_add_int(tmp2->connect, tmp->rom);
	tmp->connect = ft_add_int(tmp->connect, tmp2->rom);
	free(inp);
	return (5);
}

void	b_one_two(t_lem *st, char *inp, int b)
{
	int		c;
	if (b == 1)
	{
		if (((c = get_next_line(0, &inp)) > 0) && (valid_line(inp, st) == 4))
			search_start(inp, st);
		else if (__builtin_printf("ERROR2\n"))
			exit(1);
	}
	else if (b == 2)
	{
		if ((get_next_line(0, &inp) > 0) && (valid_line(inp, st) == 4))
			search_end(inp, st);
		else if (__builtin_printf("ERROR1\n"))
			exit(1);
	}
	free(inp);
}

int		parsing(t_lem *st)
{
	int			b;
	char		*inp;

	while (get_next_line(0, &inp) > 0)
	{
		b = 0;
		if ((st->rm == 0 && ((b = valid_line(inp, st)) > 0)) ||
				(b = save_connect(st, inp)))
		{
			if (b == 1 || b == 2)
				b_one_two(st, inp, b);
			else if (b == 3 || b == 5)
				continue ;
			else if (b == 4)
				save_room(inp, st);
		}
		else
			break ;
		free(inp);
	}
	write(1, "\n", 1);
	return (1);
}
