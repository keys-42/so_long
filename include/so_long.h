/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:04:11 by keys              #+#    #+#             */
/*   Updated: 2022/11/29 01:13:41 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H
# include "get_next_line.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_maps
{
	char	**map;
	int		fd;
}			t_maps;


/*check_arg*/
void		ft_check_arg_num(int argc, char **argv, t_maps **maps);

/*check_around_map*/
void		ft_around_map_check(t_maps **maps);

/*check_person*/
void ft_check_person(t_maps **maps);

/*check_exit*/
void	ft_check_exit(t_maps **maps);

/*make_map*/
void		ft_make_map(char *txt, t_maps **maps);

/*utils*/
void		ft_free_maps(t_maps **maps, int flag);
void		ft_free_map(char **dst);
void		ft_new_maps(t_maps **maps);
#endif
