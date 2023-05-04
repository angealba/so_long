/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:31:22 by analbarr          #+#    #+#             */
/*   Updated: 2023/04/20 19:31:33 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_game
{
	int		fd;
	int		map_height;
	int		map_width;

	char	**map;

	void	*floor;
	void	*wall;
	void	*exit;
	void	*collectable;
	void	*mlx;
	void	*mlx_win;
}	t_game;

/*Init*/
void	*ft_memset(void *b, int c, size_t len);

/*map*/
void	check_map_ext(char *map, char *ext);
int		get_width(char *str);
int		read_map(t_game *game, char **argv);
void	check_rectangle(t_game *game);

/*game*/
int		exit_game(t_game *game);

# endif