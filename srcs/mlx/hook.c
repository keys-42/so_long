/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:35:44 by keys              #+#    #+#             */
/*   Updated: 2022/12/11 17:55:11 by keys             ###   ########.fr       */
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
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (key_num == ESC_KEY)
		ft_free_data(&data, 1, "Escape key pressed.");
	else if (key_num == -1)
		ft_free_data(&data, 1, "Congrats on the goal!");
	else
		ft_free_data(&data, 1, "window close.");
	exit(EXIT_SUCCESS);
}

int	ft_mlx_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->wall_image);
	mlx_destroy_image(data->mlx, data->collection_image);
	mlx_destroy_image(data->mlx, data->exit_image);
	mlx_destroy_image(data->mlx, data->player_image);
	mlx_destroy_image(data->mlx, data->space_image);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_data(&data, 1, "xxxxxxxxxxxxx\n");
	// lst_map_clear(&(data->map));
	// free(data->pixel_size_str);
	// free(data);
	// ft_printf("%s\n", "finish");
	exit(EXIT_SUCCESS);
	return (0);
}
