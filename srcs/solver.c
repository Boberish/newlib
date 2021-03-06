/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/09/05 11:25:11 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		solve(char *path, int y, int x, int z, int i, t_room *r)
{
	while (y <= r->r_len - 1 && x <= r->r_len - 1)
	{
		if (r->map[y][x] == 2)
		{	
			if (ft_strlen(path) < ft_strlen(r->bpath))
				r->bpath = path;
			r->tmp = path[i - 2];
			path[i - 1] = '\0';
			if (z == 0)
			{
				solve(path, ++y, r->tmp, 1, --i, r); 
			}
			else
			{
				solve(path, r->tmp, ++x, 0, --i, r); 
			}			
			return (1);
		}
		if (r->map[y][x] == '1')
		{
			if (z == 0)
			{
				if (ft_strchr(path, (x + 48)) != NULL)
					;
				else
				{
					path[i++] = x;
					solve(path, 0, x, 1, i, r); 
				}
			}
			else
			{
				if (ft_strchr(path, (y + 48)) != NULL)
					;
				else
				{
					path[i++] = (y + 48);
					solve(path, y, 0, 0, i, r); 
				}
			}	
		}
		(z == 0) ? x++ : y++;
		if (x == r->r_len)
			break;	
	}
	return (0);
}

int		ft_caller(t_room *r)
{
	int		y;
	int		x;
	int		z;
	int		i;
	char	*path;

	path = ft_strnew(r->r_len + 1);
	path[0] = '0';
	y = 0;
	x = 0;
	z = 0;
	i = 1;
	solve(path, y, x, z, i, r);

}

/*int		ugh(char *path, int y, int x, int z, int i, t_room *r)
{
	if (solve(path, 0, x, 1, i, r) == 0)
	{
		if (ft_strlen(path) < r->bpath)
			r->bpath = path;					
		solve(path, y, ++x, 0, --i, r);
	}
} */
