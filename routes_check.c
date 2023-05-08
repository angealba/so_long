/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:18:09 by analbarr          #+#    #+#             */
/*   Updated: 2023/05/08 17:19:04 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_collectables(char **map, t_game *game)
{
	int	x;
	int	y;
	int	c;

	x = 1;
	y = 0;
	c = 0;
	while(++y < game->map_height)
	{
		x = 0;
		while (++x < game->map_width)
		{
			if (cpy[y][x] == 'C')
				c++;
		}
	}
	return (c);
}

static void	player_pos(char **map, t_game *game)
{
	while(game->p_y < game->map_height && cpy[game->p_y][game->p_x] != 'P')
	{
		game->p_x = 1;
		while(game->p_x < game->map_width && cpy[game->p_y][game->p_x] != 'P')
		{
			if(cpy[game->p_y][game->p_x] == 'P')
				break ;
			game->p_x++;
		}
		if(cpy[game->p_y][game->p_x] == 'P')
			break ;
		game->p_y++;
	}
}

static void	route_c(char **map, t_game *game, int x, int y)
{
	
}

void	check_route(char **map, t_game *game)
{
	int	c;
	int	line;

	line = 0;
	c = count_collectables(cpy, game);
	player_pos(cpy, game);
	route_c(cpy, game, game->p_x,  game->p_y);


}