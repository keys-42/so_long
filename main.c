/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:00:51 by keys              #+#    #+#             */
/*   Updated: 2022/11/27 04:55:21 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_map_free(char **map)
// {
// 	int	i;

// 	i = 0;
// 	if (map)
// 	{
// 		while (map[i])
// 			i++;
// 		i--;
// 		while (i--)
// 			free(map[i]);
// 		free(map);
// 	}
// }

// void	ft_square_check(char **map)
// {
// 	int	i;
// 	int	row;

// 	i = 0;
// 	row = ft_strlen(map[i]);
// 	while (1)
// 	{
// 		if (row != ft_strlen(map[i]))
// 		{
// 			ft_printf("no_square\n");
// 			ft_map_free(map);
// 			exit(EXIT_FAILURE);
// 		}
// 		i++;
// 	}
// }

// void	ft_wall_check_horizontal(char **map, char *horizontal)
// {
// 	int	i;

// 	i = 0;
// 	while (horizontal[i])
// 	{
// 		if (horizontal[i] != 1)
// 		{
// 			ft_map_free(map);
// 			ft_printf("wall_Error\n");
// 			exit(EXIT_FAILURE);
// 		}
// 		i++;
// 	}
// }
// void	ft_wall_check_vertical(char **map, char *vertical)
// {
// 	int	i;

// 	i = 0;
// 	if (vertical[i] == 1)
// 	{
// 		while (vertical[i])
// 			i++;
// 		i -= 2;
// 		if (vertical[i] == 1)
// 			return ;
// 	}
// 	ft_map_free(map);
// 	ft_printf("wall_Error\n");
// 	exit(EXIT_FAILURE);
// }

// void	ft_wall_check(char **map)
// {
// 	int	i;

// 	i = 0;
// 	ft_wall_check_horizontal(map, map[i]);
// 	while (map[i + 1])
// 	{
// 		ft_wall_check_vertical(map, map[i]);
// 		i++;
// 	}
// 	ft_wall_check_horizontal(map, map[i]);
// }

// void	ft_check_arg(t_map maps, int argc, char **argv)
// {
// 	int	file_descriptor;

// 	if (argc == 2)
// 	{
// 		file_descriptor = open(argv[1], O_RDONLY);
// 		if (file_descriptor >= 0)
// 		{
// 			maps->fd = file_descriptor;
// 			ft_make_map(fd);
// 			if (map[0])
// 			{
// 				ft_square_check(map);
// 				ft_wall_check(map);
// 				close(fd);
// 				return ;
// 			}
// 		}
// 	}
// 	close(fd);
// 	exit(EXIT_FAILURE);
// }

void	ft_check_arg_num(int argc)
{
	if (argc != 2)
		exit(EXIT_FAILURE);
}

// void	*ft_realloc(void **memory, size_t size)
// {
// 	void	*tmp;

// 	if (!(*memory))
// 		return (0);
// 	tmp = malloc(size);
// 	if (!tmp)
// 	{
// 		free(*memory);
// 		return (0);
// 	}
// 	ft_memorymove(tmp, (*memory), size);
// 	free(*memory);
// 	*memory = 0;
// 	return (tmp);
// }

void	ft_split_free(char **argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
			i++;
		i--;
		while (i >= 0)
		{
			free(argv[i]);
			i--;
		}
		free(argv);
	}
}

size_t	ft_split_len(char **argv)
{
	size_t	len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

char	**ft_malloc_gnl(char **map)
{
	char	**tmp;
	size_t	size;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_split_len(map);
	tmp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (NULL);
	tmp[size] = NULL;
	while (size--)
	{
		len = ft_strlen(map[len]);
		ft_memmove(tmp[size], map[size], len + 1);
	}
	ft_split_free(map);
	return (tmp);
}

char	**ft_get_map(int file_descriptor)
{
	char	**map;
	char	*tmp;
	size_t	i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * 1);
	if (!map)
		exit(EXIT_FAILURE);
	while (1)
	{
		map[i] = get_next_line(file_descriptor);
		if (!map[i])
			break ;
		i++;
		map = ft_malloc_gnl(map);
	}
	return (map);
}

void	ft_make_map(char *txt)
{
	int		file_descriptor;
	char	**map;

	file_descriptor = open(txt, O_RDONLY);
	if (file_descriptor < 0)
		exit(EXIT_FAILURE);
	ft_get_map(file_descriptor);
	// return (maps);
}

int	main(int argc, char **argv)
{
	// t_maps	*maps;
	ft_check_arg_num(argc);
	// maps = malloc(sizeof(t_maps));
	ft_make_map(argv[1]);
	// maps = ft_make_map(argv[1]);
	// ft_check_map();
	return (0);
}
