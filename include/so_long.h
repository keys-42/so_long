/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:04:11 by keys              #+#    #+#             */
/*   Updated: 2022/11/29 17:43:33 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_maps
{
	char	**map;
	int		fd;
	size_t	map_hight;
}			t_maps;

/*check_arg*/
void		ft_check_arg_num(int argc, char **argv, t_maps **maps);

/*check_around_map*/
void		ft_around_map_check(t_maps **maps);

/*check_person*/
void		ft_check_player(t_maps **maps);

/*check_exit*/
void		ft_check_exit(t_maps **maps);

/*check_collection.c*/
void		ft_check_collectible(t_maps **maps);

/*check_square*/
void		ft_check_square(t_maps **maps);

/*check_useless*/
void		ft_useless_characters(t_maps **maps);

/*make_map*/
void		ft_make_map(char *txt, t_maps **maps);

/*utils*/
void		ft_free_maps(t_maps **maps, int flag);
void		ft_new_maps(t_maps **maps);
#endif
