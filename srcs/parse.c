/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/05/29 18:30:32 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_ants(t_room *r)
{
	int	k;

	k = 0;
	while (r->input[0][k])
	{	
		if (ft_isdigit(r->input[0][k]) == 0)
		{
			ft_putstr_fd("Major problem with number of ants", 2);
			return (-1);
		}
		else
			k++;
	}
	r->ants = ft_atoi(*r->input);
}

int		parse_start(t_room *r)	
{
	int 	k;
	int 	i;
	char 	**nstart;
	char	**mstart;

	k = 1;
	i = 1;
	nstart = r->connection;
	mstart = r->comments;
	while (r->input[k])
	{
		if (which_one(r, &k, &i) == -1)
			return (-1);
		k++;
	}
	*r->connection = 0;
	r->connection = nstart;
	r->comments = mstart;
	if (error_check(r) == -1)
		return (-1);
	init_map(r);
	move_end(r, --i);
}

int		which_one(t_room *r, int *k, int *i)
{
	if (r->input[*k][0] == '#')
	{
		if (r->input[*k][1] == '#')
		{
			if (ft_strcmp(&r->input[*k][2], "start") == 0)
				 return ((found_start(r, k)) ? 0 : -1);
			if (ft_strcmp(&r->input[*k][2], "end") == 0)
				 return ((found_end(r, k, i)) ? 0 : -1);
		}
		comment_parse(r, *k);
		return (0);
	}
	if (ft_strchr(r->input[*k], '-'))
		connection_parse(r, *k, i);
	if (ft_strchr(r->input[*k], ' '))
	{
		if (room_parse(r, *k, i) == -1)
			return (-1);
	}
}

int		if_valid_room(t_room *r, int k)
{
	char	*space;
	int		f;

	f = 0;
	if ((space = ft_strchr(r->input[k], ' ')) == NULL)
	{	
		ft_putstr_fd("Major error, room position problem", 2);
		return (0);
	}
	space++;
	while (*space)
    {
		if (f == 1 && *space == ' ')
			break;
        if (ft_isdigit(*space++) != 0)
			f = 1;
		else
		{
			ft_putstr_fd("Major error, room position problem", 2);
            return (0);
		}
    }
	if (if_valid2(r, space) == 0)
		return (0);
	return (1);
}
