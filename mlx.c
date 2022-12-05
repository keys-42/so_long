/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:20:48 by kyoda             #+#    #+#             */
/*   Updated: 2022/12/05 14:32:45 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_mlx(t_mlx_utils **data)
{
    (*data)->mlx = mlx_init();
    (*data)->mlx_win = mlx_new_window((*data)->mlx,pixel_hight,pixel_width,"so_long");
    

}