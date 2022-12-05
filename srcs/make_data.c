/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:47:16 by keys              #+#    #+#             */
/*   Updated: 2022/12/05 16:07:13 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx_utils	*ft_make_data(t_maps **maps)
{
	int	j;
	int	i;

	i = 0;
	while ((*maps)->map[i])
	{
		j = 0;
		while ((*maps)->map[i][j])
		{
			printf("%c", (*maps)->map[i][j]);
			j++;
		}
		i++;
	}
	printf("hi=%ld\n",(*maps)->hight);
	printf("wi=%ld\n",(*maps)->width);
	printf("i=%d\n",(*maps)->player_i);
	printf("j=%d\n",(*maps)->player_j);
	return (NULL);
}
