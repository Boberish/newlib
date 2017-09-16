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

int		parse_start_end(t_room *r, int fd)
{
	char	*line;
	
	get_next_line(fd, &line);
	while (*line)
	{
		line++;
	}
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		which_one(r, line);
	}
	return (1);
}

int		which_one(t_room *r, char *line)
{
	int i;
	
	i = 0;
	if (line[i] == '#' && line[i + 1] == '#')
	{
		if (line[i + 2] == 's')
			room_parse(r, line);
		if (line[i + 2] == 'e')
			room_parse(r, line);
	}
	if (ft_strchr('-', line))
			connection_parse(r, line);
	if (ft_strchr(' ', line))
		room_parse(r, line);
	
}

int		if_valid(t_room *r, char *line)
{
	int	i;
	int x;
	int y;
	
	i = 0;
	while (line[i] != ' ')
		i++;
	x = ft_atoi(line[i]);
	y = ft_atoi(line[i + ft_intlen(x)]);
	return (ft_isdigit(x) + ft_isdigit(y));
}
