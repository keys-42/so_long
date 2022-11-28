/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_around_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:54:12 by keys              #+#    #+#             */
/*   Updated: 2022/11/29 00:40:40 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_side_wall_check(char *line)
{
	int	i;

	i = 0;
	if (line[0] != '1')
		return (false);
	while (line[i] != '\n')
		i++;
	if (line[i - 1] != '1')
		return (false);
	return (true);
}

static bool	ft_upper_lower_wall_check(char *line)
{
	int i;

	i = 0;
	while (1)
	{
		if (line[i] != '1')
		{
			printf("i = %d;if = %c",i,line[i]);
			return (false);
		}
		i++;
		if(line[i] == '\n')
			break;
	}
	return (true);
}

void	ft_around_map_check(t_maps **maps)
{
	int		i;
	bool	flag;

	i = 0;
	while ((*maps)->map[i])
	{
		if (i == 0)
		{
			flag = ft_upper_lower_wall_check((*maps)->map[i]);
			if (flag == false)
			{
				printf("upper\n");
				ft_free_maps(maps, 1);
			}
		}
		else if ((*maps)->map[i + 1] == NULL)
		{
			flag = ft_upper_lower_wall_check((*maps)->map[i]);
			if (flag == false)
			{
				printf("lower\n");
				ft_free_maps(maps, 1);
			}
		}
		else
		{
			flag = ft_side_wall_check((*maps)->map[i]);
			if (flag == false)
			{
				printf("side\n");
				ft_free_maps(maps, 1);
			}
		}
		i++;
	}
}
