/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2017/05/29 18:30:32 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print2d(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		ft_putstr(array[i++]);
		ft_putchar('\n');
	}
	return (0);
}

