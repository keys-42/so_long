/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:32:03 by keys              #+#    #+#             */
/*   Updated: 2022/12/09 23:23:07 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_maps	*maps;
	t_data	*data;
	// int		i;

	if (argc != 2)
		return (0);
	ft_new_maps(&maps);
	ft_checks(argv, maps);
	ft_new_data(&data, &maps);
	ft_mlx_make(data);
	// printf("_______________________________________________________________\n");
	// i = 0;
	// while (data->map[i])
	// {
	// 	printf("%s\n", data->map[i]);
	// 	i++;
	// }
	// printf("_______________________________________________________________\n");
	fflush(stdout);
	ft_free_data(&data, 1, NULL);
}
