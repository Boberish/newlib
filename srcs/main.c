/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/09/05 11:26:34 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <fcntl.h>
int main(int argc, char **argv)
{
	t_room	*r;
	int		fd;
	
	fd = open(argv[1], O_RDONLY);
	r = (t_room*)malloc(sizeof(t_room));
	init_rooms(r);
	get_input(r, fd);
	if (get_ants(r) == -1)
		return (-1);
	if (parse_start(r) == -1)
		return (-1);
	add_con_to_map(r);
	print_input(r);
	ft_caller(r);
	ft_putstr(r->bpath);		
}
