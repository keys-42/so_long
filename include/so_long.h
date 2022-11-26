/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:04:11 by keys              #+#    #+#             */
/*   Updated: 2022/11/27 02:50:12 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H
// # include "ft_printf/include/ft_printf.h"
// # include "ft_printf.h"
# include "../ft_printf/include/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_map
{
	char	**map;
	int fd;
}			t_map;
#endif
