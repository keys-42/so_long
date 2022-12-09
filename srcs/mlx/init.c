/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:33:23 by keys              #+#    #+#             */
/*   Updated: 2022/12/09 23:33:52 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_image_init(t_data *data)
{
	int	hight;
	int	width;

	hight = WINDOWSIZE;
	width = WINDOWSIZE;
	data->wall_image = mlx_xpm_file_to_image(data->mlx,
												"./images/wall-_1_.xpm",
												&hight,
												&width);
	data->space_image = mlx_xpm_file_to_image(data->mlx,
												"./images/white-_1_.xpm",
												&hight,
												&width);
	data->player_image = mlx_xpm_file_to_image(data->mlx,
												"./images/sanji.xpm",
												&hight,
												&width);
	data->collection_image = mlx_xpm_file_to_image(data->mlx,
													"./images/chopper.xpm",
													&hight,
													&width);
	data->exit_image = mlx_xpm_file_to_image(data->mlx,
												"./images/nami.xpm",
												&hight,
												&width);
}
