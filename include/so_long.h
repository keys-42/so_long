/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:04:11 by keys              #+#    #+#             */
/*   Updated: 2022/12/09 23:47:15 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
// # include <minilibx-linux/mlx.h>
# include <sys/stat.h>
# include <sys/types.h>

# define PIXEL_HIGTH 1980
# define PIXEL_WIDTH 1080
# define WINDOWSIZE 50
//shift
# define ESC_KEY 65307
# define UP_KEY 119
# define DOWN_KEY 115
# define LEFT_KEY 97
# define RIGHT_KEY 100

typedef struct s_maps
{
	char	**map;
	int		map_flag;
	char	**dfs_flag;
	int		fd;
	int		hight;
	int		width;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collection_num;
	int		flag;
}			t_maps;

typedef struct s_data
{
	t_maps	*maps;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*wall_image;
	void	*space_image;
	void	*player_image;
	void	*collection_image;
	void	*exit_image;
	int		player_x;
	int		player_y;
	int		hight;
	int		width;

}			t_data;

void		ft_checks(char **argv, t_maps *maps);
void		ft_free_maps(t_maps **maps, int flag, char *error_message);
void		ft_free_map(char **dst);
void		ft_make_map(char *txt, t_maps *maps);
void		ft_check_square(t_maps *maps);
void		ft_new_maps(t_maps **maps);
void		ft_check_wall(t_maps *maps);
void		ft_check_player(t_maps *maps);
void		ft_check_exit(t_maps *maps);
void		ft_set_coordinate(char *line, char c, int *x);
int			ft_find_character(char *line, char c);
void		ft_check_collectibles(t_maps *maps);
void		ft_check_use_characters(t_maps *maps);
void		ft_check_can_finish(t_maps *maps);
void		ft_new_data(t_data **data, t_maps **maps);
void		ft_free_data(t_data **data, int flag, char *error_message);
void		ft_mlx_make(t_data *data);
int			ft_close(int key_num, t_data *data);
int			ft_painting(t_data *data);
void		mlx_image_init(t_data *data);
int			ft_map_swap(int key_num, t_data *data);

#endif
