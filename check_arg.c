/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:47:13 by keys              #+#    #+#             */
/*   Updated: 2022/11/29 01:14:13 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_arg_num(int argc, char **argv, t_maps **maps)
{
	if (argc != 2)
		ft_free_maps(maps, 1);
	else
	{
		ft_make_map(argv[1], maps);
		ft_around_map_check(&(*maps));
		ft_check_person(&(*maps));
		ft_check_exit(&(*maps));
	}
}
