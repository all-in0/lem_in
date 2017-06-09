/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:01:06 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/20 15:25:55 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include <string.h>

/*
 ** if buff_size == 2 || 4 || 6 then
 **   one of moulitests fails // WTF?!
 */

# define BUFF_SIZE 4096

typedef struct  s_fd_list
{
    int                 fd;
    size_t              rest_index;
    char                *line;
    struct s_fd_list    *next;
    char                rest[BUFF_SIZE + 1];
}               t_fd_list;

#endif

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

t_fd_list   *lst_get(t_fd_list **lst, const int fd)
{
    if (!(*lst))
    {
        *lst = (t_fd_list *)malloc(sizeof(t_fd_list));
        (*lst)->fd = fd;
        ft_bzero((*lst)->rest, sizeof((*lst)->rest));
        (*lst)->rest_index = 0;
        (*lst)->line = 0;
        (*lst)->next = 0;
        return (*lst);
    }
    else if ((*lst)->fd == fd)
        return (*lst);
    else
        return (lst_get(&(*lst)->next, fd));
}

int         str_concat(char **dest, const char *src)
{
    int     dest_len;
    int     src_len;
    char    *res;
    
    dest_len = *dest ? ft_strlen(*dest) : 0;
    src_len = 0;
    while (src[src_len] && src[src_len] != '\n')
        src_len++;
    res = (char *)malloc(dest_len + src_len + 1);
    if (*dest)
    {
        ft_strcpy(res, *dest);
        ft_strncat(res, src, src_len);
        free(*dest);
    }
    else
        ft_strncpy(res, src, src_len);
    res[dest_len + src_len] = 0;
    *dest = res;
    return (src_len);
}

int         get_next_line_e(t_fd_list *curr, const int fd, char **line)
{
    int                 nread;
    
    if ((nread = read(curr->fd, curr->rest, BUFF_SIZE)) < 0)
        return (-1);
    curr->rest_index = 0;
    if (curr->line && nread == 0)
    {
        *line = curr->line;
        curr->line = 0;
        return (1);
    }
    else if (nread == 0)
    {
        *line = 0;
        curr->line = 0;
        ft_bzero(curr->rest, sizeof(curr->rest));
        return (0);
    }
    return (get_next_line(fd, line));
}

int         get_next_line_ne_n(t_fd_list *curr, const char *nl, char **line)
{
    int                 diff;
    
    diff = nl - &curr->rest[curr->rest_index];
    str_concat(&curr->line, &curr->rest[curr->rest_index]);
    curr->rest_index += diff + 1;
    *line = curr->line;
    curr->line = 0;
    return (1);
}

int         get_next_line(const int fd, char **line)
{
    static t_fd_list    *lst = 0;
    t_fd_list           *curr;
    int                 nread;
    char                *newline;
    
    curr = lst_get(&lst, fd);
    if (curr->rest[curr->rest_index])
    {
        newline = ft_strchr(&curr->rest[curr->rest_index], '\n');
        if (newline)
            return (get_next_line_ne_n(curr, newline, line));
        else
        {
            str_concat(&curr->line, &curr->rest[curr->rest_index]);
            if ((nread = read(curr->fd, curr->rest, BUFF_SIZE)) < 0)
                return (-1);
            curr->rest[nread] = 0;
            curr->rest_index = 0;
            return (get_next_line(fd, line));
        }
    }
    return (get_next_line_e(curr, fd, line));
}
