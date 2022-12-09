/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:35:44 by keys              #+#    #+#             */
/*   Updated: 2022/12/10 00:28:45 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int key_num, t_data *data)
{
	if (key_num == ESC_KEY)
	{
		mlx_destroy_image(data->mlx, data->wall_image);
		mlx_destroy_image(data->mlx, data->space_image);
		mlx_destroy_image(data->mlx, data->player_image);
		mlx_destroy_image(data->mlx, data->exit_image);
		mlx_destroy_image(data->mlx, data->collection_image);
		ft_free_data(&data, 1, "Escape key pressed.");
	}
	return (0);
}
