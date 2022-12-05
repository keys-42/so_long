/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:02:48 by keys              #+#    #+#             */
/*   Updated: 2022/12/05 15:07:21 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_utils_free(t_mlx_utils **data)
{
	ft_free_maps(&(*data)->maps,1);
}

void	ft_free_map(char **dst)
{
	int	i;

	i = 0;
	if (dst)
	{
		while (dst[i])
		{
			free(dst[i]);
			i++;
		}
		free(dst);
	}
}

void	ft_free_maps(t_maps **maps, int flag)
{
	if (*maps)
	{
		if ((*maps)->map)
			ft_free_map((*maps)->map);
		if((*maps)->fd)
			close((*maps)->fd);
		free(*maps);
	}
	if (flag == 1)
		exit(EXIT_FAILURE);
}

void	ft_new_maps(t_maps **maps)
{
	*maps = (t_maps *)malloc(sizeof(t_maps));
	if (!maps)
		exit(EXIT_FAILURE);
	(*maps)->map = NULL;
	(*maps)->fd = 0;
}
