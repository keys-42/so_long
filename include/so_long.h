/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:04:11 by keys              #+#    #+#             */
/*   Updated: 2022/12/05 15:06:05 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <sys/stat.h>
# include <sys/types.h>

# define pixel_width 1920
# define pixel_hight 1080
# define wall_image_pass "./images/wall-_1_.xpm"
# define space_image_pass "./images/white-_1_.xpm"
# define player_image_pass "./images/lucas-3__3.xpm"
# define collection_image_pass "./images/ball-_1_.xpm"
# define exit_image_pass "./images/exit1.xpm"
// # define WINDOW_SIZE 500
typedef struct s_maps
{
	char	**map;
	int		fd;
	size_t	hight;
	size_t	width;
	int		player_i;
	int		player_j;
}			t_maps;

typedef struct s_mlx_utils
{
	void	*mlx;
	void	*mlx_win;
	void	*wall_image;
	void	*space_image;
	void	*player_image;
	void	*collection_image;
	void	*exit_image;
	t_maps	*maps;

}			t_mlx_utils;

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

/*dfs*/
void		dfs(t_maps **maps);

/*make_map*/
void		ft_make_map(char *txt, t_maps **maps);

/*MLX*/
void		ft_mlx(t_mlx_utils **data);

/*utils*/
void		ft_free_map(char **dst);
void		ft_free_maps(t_maps **maps, int flag);
void		ft_new_maps(t_maps **maps);
#endif
