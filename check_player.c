/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:37:08 by keys              #+#    #+#             */
/*   Updated: 2022/11/29 16:46:01 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_player_check(char *line)
{
	int	i;
	int	ans;

	ans = 0;
	i = 1;
	while (1)
	{
		if (line[i + 1] == '\n')
			break ;
		else
		{
			if (line[i] == 'P')
				ans++;
		}
		i++;
	}
	return (ans);
}

void	ft_check_player(t_maps **maps)
{
	size_t	i;
	int	num;

	i = 0;
	num = 0;
	while ((*maps)->map[i])
	{
		if ((*maps)->map[i + 1] == NULL)
			return;
		else if (i == 0)
		{
			i++;
			continue ;
		}
		else
		{
			num += ft_player_check((*maps)->map[i]);
		}
		i++;
	}
	if (num < 1 || 2 <= num)
	{
		printf("player\n");
		ft_free_maps(maps, 1);
	}
}
