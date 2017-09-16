/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/05/29 18:30:32 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		room_parse(t_room *r, int k, int *i)
{
	if (if_valid_room(r, k) == 0)
		return (-1);
	chop_at_space(r, k);
	r->rooms[(*i)++] = r->input[k];
	return (0);
}

int 	move_end(t_room *r, int i)
{
	char	*tmp;
	
	tmp = r->rooms[i]; 
	r->rooms[i] = r->rooms[r->end];
	r->rooms[r->end] = tmp;
	r->end = i;
	return (1);
}

int		connection_parse(t_room *r, int k, int *i)
{
	if (if_valid_con(r, k) == 1)
		room_parse(r, k, *i);
	else
	{
		*r->connection = r->input[k];
		r->connection++;
	}
}

int		found_start(t_room *r, int *k)
{
	while (r->input[++(*k)][0] == '#')
		comment_parse(r, *k);
	if (if_valid_room(r, *k) == 0)
		return (0);
	chop_at_space(r, *k);
	r->rooms[0] = r->input[*k];
	return (1);
}

int		found_end(t_room *r, int *k, int *i)
{
	while (r->input[++(*k)][0] == '#')
		comment_parse(r, *k);
	if (if_valid_room(r, *k) == 0)
		return (0);
	chop_at_space(r, *k);
	r->end = *i;
	r->rooms[(*i)++] = r->input[*k];
	return (1);
}
