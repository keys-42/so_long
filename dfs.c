/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:53:38 by keys              #+#    #+#             */
/*   Updated: 2022/12/01 23:06:02 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	VertSearch(int i, int j, char **map, int *flag)
{
	printf("{%d,%d}\n", i, j);
	map[i][j] = '!';
	if (map[i + 1][j] == 'E' || map[i - 1][j] == 'E' || map[i][j - 1] == 'E'
		|| map[i][j + 1] == 'E')
	{
		printf("suc\n");
		*flag = 1;
		return ;
	}
	if (map[i][j - 1] == '0' && map[i][j - 1] == '0')
	{
		if (*flag == 1)
			return ;
		VertSearch(i, j - 1, map, flag);
	}
	if (map[i - 1][j] == '0' && map[i - 1][j] == '0')
	{
		if (*flag == 1)
			return ;
		VertSearch(i - 1, j, map, flag);
	}
	if (map[i][j + 1] == '0' && map[i][j + 1] == '0')
	{
		if (*flag == 1)
			return ;
		VertSearch(i, j + 1, map, flag);
	}
	if (map[i + 1][j] == '0' && map[i + 1][j] == '0')
	{
		if (*flag == 1)
			return ;
		VertSearch(i + 1, j, map, flag);
	}
}

void	dfs(t_maps **maps)
{
	int	*flag;

	flag = (int *)malloc(sizeof(int) * 1);
	if (!flag)
		ft_free_maps(maps, 1);
	*flag = 0;
	VertSearch((*maps)->player_i, (*maps)->player_j, (*maps)->map, flag);
	if (*flag == 0)
	{
		printf("Where is the goal?\n");
		ft_free_maps(maps, 1);
	}
	free(flag);
}
