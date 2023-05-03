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

typedef struct s_game
{
	int		fd;
	int		map_height;
	int		map_widht;

	char	**map;

	void	*floor;
	void	*wall;
	void	*exit;
	void	*collectable;
	void	*mlx;
	void	*win;
}	t_game;
