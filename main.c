/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:00:51 by keys              #+#    #+#             */
/*   Updated: 2022/12/05 15:06:27 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_maps	*maps;
	t_mlx_utils *data;

	ft_new_maps(&maps);
	ft_check_arg_num(argc, argv, &maps);
	data= NULL;
	data->maps=maps;
	ft_mlx(&data);

	// int i;
	// i = 0;
	// while(maps->map[i])
	// {
	// 	printf("%d =%s",i,maps->map[i]);
	// 	i++;
	// }
	ft_free_maps(&maps, 1);
	return (0);
}
