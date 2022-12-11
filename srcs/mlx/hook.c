/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:35:44 by keys              #+#    #+#             */
/*   Updated: 2022/12/11 16:14:08 by keys             ###   ########.fr       */
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
	else if (key_num == -1)
		ft_free_data(&data, 1, "Congrats on the goal!");
	else
		ft_free_data(&data, 1, "window close.");
	exit(EXIT_SUCCESS);
}

int	ft_close_x(int key_num, t_data **data)
{
	key_num--;
	mlx_destroy_image((*data)->mlx, (*data)->wall_image);
	mlx_destroy_image((*data)->mlx, (*data)->space_image);
	mlx_destroy_image((*data)->mlx, (*data)->player_image);
	mlx_destroy_image((*data)->mlx, (*data)->exit_image);
	mlx_destroy_image((*data)->mlx, (*data)->collection_image);
	ft_free_data(data, 1, "window close.");
	exit(EXIT_SUCCESS);
}

	// printf("key=%d\n",key_num);
	// fflush(stdout);
