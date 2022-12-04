/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:11:22 by keys              #+#    #+#             */
/*   Updated: 2022/12/02 20:15:08 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mlx_image_init(t_mlx_utils **data)
{
	int	size;

	size = WINDOW_SIZE;
	(*data)->wall_image = mlx_xpm_file_to_image((*data)->mlx,
												"./images/wall-_1_.xpm",
												&size,
												&size);
	(*data)->space_image = mlx_xpm_file_to_image((*data)->mlx,
													"./images/white-_1_.xpm",
													&size,
													&size);
	(*data)->player_image = mlx_xpm_file_to_image((*data)->mlx,
													"./images/lucas-_3__3.xpm",
													&size,
													&size);
	(*data)->collection_image = mlx_xpm_file_to_image((*data)->mlx,
														"./images/ball-_1_.xpm",
														&size,
														&size);
	(*data)->exit_image = mlx_xpm_file_to_image((*data)->mlx,
												"./images/exit1.xpm",
												&size,
												&size);
}

void	ft_mlx_init(t_mlx_utils **data)
{
	(*data)->mlx = mlx_init();
	if (!(*data)->mlx)
		ft_mlx_utils_free(&(*data));
	(*data)->mlx_win = mlx_new_window((*data)->mlx, WINDOW_SIZE
			* ((*data)->maps->width), WINDOW_SIZE * (*data)->maps->hight,
			"so_long");
	mlx_image_init(&(*data));
}
