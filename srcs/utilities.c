#include "lemin.h"

int		init_rooms(t_room *r)
{
	r->rooms = (char**)malloc(sizeof(char*) * 5000);
	ft_memset(r->rooms, 0, 5000);
   	r->rooms[0] = 28;	
	r->input = (char**)malloc(sizeof(char*) * 5000);
	ft_memset(r->input, 0, 5000); 
	r->connection = (char**)malloc(sizeof(char*) * 5000);
	r->comments = (char**)malloc(sizeof(char*) * 5000);
	ft_memset(r->comments, 0, 5000); 
	r->end = 0;
}

int		chop_at_space(t_room *r, int k)
{
	char	*space;

	space = ft_strchr(r->input[k], ' ');
	*space = '\0';
}

int		init_map(t_room *r)
{
	int i;

	i = 0;
	r->map = (int**)malloc(sizeof(int*) * r->r_len);
	while (i < r->r_len)
	{
		r->map[i] = malloc(sizeof(int) * r->r_len);
		ft_memset(r->map[i++], 0, r->r_len);
	}
}

int     get_input(t_room *r, int fd)
{
    char    *line;

    r->start = r->input;
    while (get_next_line(fd, &line) > 0)
    {
        *r->input = ft_strdup(line);
        r->input++;
        free(line);
    }
    *r->input = 0;
    r->input = r->start;
}

int		error_check(t_room *r)
{
	if (r->end == 0)
		{
			ft_putstr_fd("Major error, no end room", 2);
			return (-1);
		}
		if (r->rooms[0] == 28)
		{
			ft_putstr_fd("Major error, no start room", 2);
			return (-1);
		}
	r->r_len = ft_list_len(r->rooms);
	r->bpath = ft_strnew(r->r_len);
	ft_memset(r->bpath, 28, r->r_len);
	if (r->r_len == 0)
	{
		ft_putstr_fd("Major error, no rooms!", 2);
		return (-1);
	}
	if (ft_list_len(r->connection) == 0)
	{
		ft_putstr_fd("Major error, no connections!", 2);
		return (-1);
	}	

}
