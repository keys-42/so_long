/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:25:01 by keys              #+#    #+#             */
/*   Updated: 2022/11/29 16:51:08 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_collectible_check(char *line)
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
			if (line[i] == 'C')
				ans++;
		}
		i++;
	}
	return (ans);
}

void	ft_check_collectible(t_maps **maps)
{
	size_t	i;
	int		num;

	i = 1;
	num = 0;
	while ((*maps)->map[i])
	{
		if ((*maps)->map[i + 1] == NULL)
			break ;
		else
		{
			num += ft_collectible_check((*maps)->map[i]);
		}
		i++;
	}
	if (num < 1)
	{
		printf("collectible\n");
		ft_free_maps(maps, 1);
	}
}
