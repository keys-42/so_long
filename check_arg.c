/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:47:13 by keys              #+#    #+#             */
/*   Updated: 2022/11/29 17:16:53 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_filename_check(char *filename, t_maps **maps)
{
	size_t	i;

	i = ft_strlen(filename);
	filename[i] == NULL;
	if (ft_strncmp(&filename[i - 3], ".ber"))
		return ;
	else
	{
		ft_free_maps(maps, 1);
		exit(1);
	}
}

void	ft_check_arg_num(int argc, char **argv, t_maps **maps)
{
	if (argc != 2)
		ft_free_maps(maps, 1);
	else
	{
		ft_filename_check(argv[1], &(*maps));
		ft_make_map(argv[1], maps);
		printf("line = %d\n", __LINE__);
		ft_around_map_check(&(*maps));
		printf("line = %d\n", __LINE__);
		ft_check_player(&(*maps));
		printf("line = %d\n", __LINE__);
		ft_check_exit(&(*maps));
		printf("line = %d\n", __LINE__);
		ft_check_collectible(&(*maps));
		printf("line = %d\n", __LINE__);
		ft_check_square(&(*maps));
		printf("line = %d\n", __LINE__);
		ft_useless_characters(&(*maps));
		printf("line = %d\n", __LINE__);
	}
}
