/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_person.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:37:08 by keys              #+#    #+#             */
/*   Updated: 2022/11/29 01:10:15 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_person_check(char *line)
{
	int	i;
	int	ans;

	ans = 0;
	i = 1;
	while (1)
	{
		if (line[i + 1] == '\n')
			break ;
		else
		{
			if (line[i] == 'P')
				ans++;
		}
		i++;
	}
	return (ans);
}

void	ft_check_person(t_maps **maps)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while ((*maps)->map[i])
	{
		if (i == 0 || (*maps)->map[i + 1] == NULL)
		{
			i++;
			continue ;
		}
		else
		{
			num += ft_person_check((*maps)->map[i]);
		}
		i++;
	}
	if (num < 1 || 2 <= num)
	{
		printf("person\n");
		ft_free_maps(maps, 1);
	}
}
