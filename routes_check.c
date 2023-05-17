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

static void	player_pos(char **cpy, t_game *game)
{
	while (game->p_y < game->map_height && cpy[game->p_y][game->p_x] != 'P')
	{
		game->p_x = 1;
		while (game->p_x < game->map_width && cpy[game->p_y][game->p_x] != 'P')
		{
			if (cpy[game->p_y][game->p_x] == 'P')
				break ;
			game->p_x++;
		}
		if (cpy[game->p_y][game->p_x] == 'P')
			break ;
		game->p_y++;
	}
}

static void	route_c(char **cpy, t_game *game, int x, int y)
{
	if (cpy[y][x] == 'C')
		game->c_check++;
	if (cpy[y - 1][x] == '0' || cpy[y + 1][x] == '0' || cpy[y][x - 1] == '0'
		|| cpy[y][x + 1] == '0' || cpy[y - 1][x] == 'C' || cpy[y + 1][x] == 'C'
		|| cpy[y][x - 1] == 'C' || cpy[y][x + 1] == 'C')
		cpy[y][x] = '.';
	if (cpy[y - 1][x] == '0' || cpy[y - 1][x] == 'C')
		route_c(cpy, game, x, y - 1);
	if (cpy[y + 1][x] == '0' || cpy[y + 1][x] == 'C')
		route_c(cpy, game, x, y + 1);
	if (cpy[y][x - 1] == '0' || cpy[y][x - 1] == 'C')
		route_c(cpy, game, x - 1, y);
	if (cpy[y][x + 1] == '0' || cpy[y][x + 1] == 'C')
		route_c(cpy, game, x + 1, y);
	cpy[y][x] = '.';
}

static void	route_e(char **cpy, t_game *game, int x, int y)
{
	if (cpy[y][x] == 'E')
		game->e_check++;
	if (cpy[y - 1][x] == '0' || cpy[y + 1][x] == '0' || cpy[y][x - 1] == '0'
		|| cpy[y][x + 1] == '0' || cpy[y - 1][x] == 'C' || cpy[y + 1][x] == 'C'
		|| cpy[y][x - 1] == 'C' || cpy[y][x + 1] == 'C')
		cpy[y][x] = '.';
	if (cpy[y - 1][x] == '0' || cpy[y - 1][x] == 'E' || cpy[y - 1][x] == 'C')
		route_e(cpy, game, x, y - 1);
	if (cpy[y + 1][x] == '0' || cpy[y + 1][x] == 'E' || cpy[y + 1][x] == 'C' )
		route_e(cpy, game, x, y + 1);
	if (cpy[y][x - 1] == '0' || cpy[y][x - 1] == 'E' || cpy[y][x - 1] == 'C')
		route_e(cpy, game, x - 1, y);
	if (cpy[y][x + 1] == '0' || cpy[y][x + 1] == 'E' || cpy[y][x + 1] == 'C')
		route_e(cpy, game, x + 1, y);
	cpy[y][x] = '.';
}

void	check_route(char **cpy, t_game *game)
{
	int	line;

	line = 0;
	player_pos(cpy, game);
	route_c(cpy, game, game->p_x, game->p_y);
	if (game->c_check != game->c_count)
	{
		printf("No valid route to pick up all collectables");
		exit_game(game);
	}
	while (line < game->map_height)
		free(cpy[line++]);
	copy_map(cpy, game);
	route_e(cpy, game, game->p_x, game->p_y);
	line = 0;
	while (line < game->map_height)
		free(cpy[line++]);
	free(cpy);
	if (game->e_check != 1)
	{
		printf("No valid route to exit");
		exit_game(game);
	}
}
