/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:35:03 by keys              #+#    #+#             */
/*   Updated: 2022/12/10 00:41:47 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap(char *x, char *y)
{
	char	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	ft_map_swap_utils(t_data *data, int y, int x)
{
	int	ix;
	int	jy;

	ix = data->player_x;
	jy = data->player_y;
	if (data->map[jy + y][ix + x] != '1')
	{
		if (data->map[jy + y][ix + x] == 'E')
		{
			if (!(data->maps->collection_num))
				ft_close(ESC_KEY, data);
			return ;
		}
		if (data->map[jy + y][ix + x] == 'C')
		{
			data->maps->collection_num--;
			data->map[jy + y][ix + x] = '0';
		}
		ft_swap(&(data->map[jy][ix]), &(data->map[jy + y][ix + x]));
		data->player_y += y;
		data->player_x += x;
	}
}

int	ft_map_swap(int key_num, t_data *data)
{
	if (key_num == ESC_KEY)
	{
		write(1, "ESC\n", 4);
		ft_close(ESC_KEY, data);
	}
	if (key_num == UP_KEY)
	{
		write(1, "upp\n", 4);
		ft_map_swap_utils(data, -1, 0);
	}
	if (key_num == RIGHT_KEY)
	{
		write(1, "rig\n", 4);
		ft_map_swap_utils(data, 0, 1);
	}
	if (key_num == LEFT_KEY)
	{
		write(1, "lef\n", 4);
		ft_map_swap_utils(data, 0, -1);
	}
	if (key_num == DOWN_KEY)
	{
		printf("do\n");
		ft_map_swap_utils(data, 1, 0);
	}
	return (0);
}
