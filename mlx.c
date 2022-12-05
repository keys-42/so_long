/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:20:48 by kyoda             #+#    #+#             */
/*   Updated: 2022/12/05 15:10:38 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_new_image(t_mlx_utils **data)
{
    int hight;
    int width;

    hight = pixel_hight;
    width = pixel_width;
    (*data)->wall_image = mlx_xpm_file_to_image((*data)->mlx,wall_image_pass,&hight,&width);
    (*data)->space_image =  mlx_xpm_file_to_image((*data)->mlx,space_image_pass,&hight,&width);
    (*data)->player_image =  mlx_xpm_file_to_image((*data)->mlx,player_image_pass,&hight,&width);
    (*data)->collection_image =  mlx_xpm_file_to_image((*data)->mlx,collection_image_pass,&hight,&width);
    (*data)->exit_image =  mlx_xpm_file_to_image((*data)->mlx,exit_image_pass,&hight,&width);
}

void	ft_mlx(t_mlx_utils **data)
{
	(*data)->mlx = mlx_init();
	(*data)->mlx_win = mlx_new_window((*data)->mlx, pixel_hight, pixel_width,
			"so_long");
	ft_mlx_new_image(data);
    
    mlx_loop((*data)->mlx);
}