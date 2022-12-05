/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:56:55 by keys              #+#    #+#             */
/*   Updated: 2022/11/29 16:49:58 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_exit_position(char *line)
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
			if (line[i] == 'E')
				ans++;
		}
		i++;
	}
	return (ans);
}

void	ft_check_exit(t_maps **maps)
{
	int	i;
	int	num;

	i = 1;
	num = 0;
	while ((*maps)->map[i])
	{
		if ((*maps)->map[i + 1] == NULL)
			return ;
		else
		{
			num += ft_exit_position((*maps)->map[i]);
		}
		i++;
	}
	if (num < 1 || 2 <= num)
	{
		printf("exit num =%d\n", num);
		ft_free_maps(maps, 1);
	}
}
