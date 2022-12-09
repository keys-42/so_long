/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:35:44 by keys              #+#    #+#             */
/*   Updated: 2022/12/10 01:40:21 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int key_num, t_data *data)
{
	mlx_destroy_image(data->mlx, data->wall_image);
	mlx_destroy_image(data->mlx, data->space_image);
	mlx_destroy_image(data->mlx, data->player_image);
	mlx_destroy_image(data->mlx, data->exit_image);
	mlx_destroy_image(data->mlx, data->collection_image);
	if (key_num == ESC_KEY)
		ft_free_data(&data, 1, "Escape key pressed.");
	else if (key_num == 0)
		ft_free_data(&data, 1, "Congrats on the goal!");
	return (0);
}
