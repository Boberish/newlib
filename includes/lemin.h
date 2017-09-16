/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/05/29 18:30:32 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/includes/libft.h"

typedef struct		s_room
{
	int				ants;
	char			**rooms;
	char			**start;
	int				end;
	char			**input;
	char			**connection;
	int				**map;
	int				r_len;
	char			**comments;
	char			*bpath;
	int				tmp;
}					t_room;

/*
**	main.c
*/

int					main(int argc, char **argv);

/*
**	initialize.c
*/

int					initialize_structs(t_room *r);

/*
**	parse.c
*/

int					get_ants(t_room *r);
int					parse_start(t_room *r);
int					which_one(t_room *r, int *k, int *i);
int					if_valid_room(t_room *r, int k);

/*
**	parse2.c
*/

int					room_parse(t_room *r, int k, int *i);
int					move_end(t_room *r, int k);
int					connection_parse(t_room *r, int k, int *i);
int					found_start(t_room *r, int *k);
int					found_end(t_room *r, int *k, int *i);

/*
**	parse3.c
*/

int     			comment_parse(t_room *r, int k);
int					if_valid2(t_room *r, char *space);
int					if_valid_con(t_room *r, int k);
int					fix_conneciton(t_room *r);
int					print_input(t_room *r);

/*
**	utilities.c
*/

int					init_rooms(t_room *r);
int					chop_at_space(t_room *r, int k);
int					init_map(t_room *r);
int					get_input(t_room *r, int fd);


/*
**	make_map.c
*/

int					add_con_to_map(t_room *r);
int					chomp_at_dash(t_room *r, int i);

/*
**	solver.c
*/

int     ft_caller(t_room *r);
int     solve(char *path, int y, int x, int z, int i, t_room *r);

#endif
