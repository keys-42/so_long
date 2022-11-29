/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:36:06 by keys              #+#    #+#             */
/*   Updated: 2022/11/29 16:53:11 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_square(t_maps **maps)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen((*maps)->map[0]);
	i = 1;
	while ((*maps)->map[i])
	{
		len2 = ft_strlen((*maps)->map[i]);
		printf("len1=%ld; len2=%ld\n",len1,len2);
		if (len1 != len2)
		{
			printf("Not_square\n");
			ft_free_maps(maps, 1);
		}
		i++;
	}
}
