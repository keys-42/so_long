/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:56:55 by keys              #+#    #+#             */
/*   Updated: 2022/11/29 01:17:10 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int ft_exit_position(char *line, int flag)
{
	int	i;
	int	ans;

	ans = 0;
	i = 0;
	while (1)
	{
		if (line[i] == '\n')
			break ;
		else
		{
			if (flag == 1 && line[i] == 'E')
				ans++;
			if (flag == 2)
			{
				if (i == 0 && line[i] == 'E')
					ans++;
				if (line[i + 2] == '\n' && line[i] == 'E')
					ans++;
			}
		}
		i++;
	}
	return (ans);
}

void	ft_check_exit(t_maps **maps)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while ((*maps)->map[i])
	{
		if (i == 0 || (*maps)->map[i + 1] == NULL)
		{
			i++;
			continue ;
		}
		else if (i == 1 || (*maps)->map[i + 2] == NULL)
		{
			num += ft_exit_position((*maps)->map[i], 1);
		}
		else
		{
			num += ft_exit_position((*maps)->map[i], 2);
		}
		i++;
	}
	if (num < 1 || 2 <= num)
	{
		printf("exit num =%d\n",num);
		ft_free_maps(maps, 1);
	}
}
