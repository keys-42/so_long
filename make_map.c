/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:46:20 by keys              #+#    #+#             */
/*   Updated: 2022/11/29 00:26:19 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_get_map(t_maps **maps, int i)
{
	char	*line;

	line = get_next_line((*maps)->fd);
	if (!line)
	{
		(*maps)->map = (char **)malloc((sizeof(char *) * (i + 1)));
		if (!((*maps)->map))
			ft_free_maps(maps, 1);
		(*maps)->map[i] = NULL;
		return ;
	}
	else
	{
		ft_get_map(maps, i + 1);
		(*maps)->map[i] = line;
		return ;
	}
}

void	ft_make_map(char *txt, t_maps **maps)
{
	(*maps)->fd = open(txt, O_RDONLY);
	if ((*maps)->fd < 0)
		ft_free_maps(maps, 1);
	ft_get_map(maps, 0);
}
