/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:52:14 by analbarr          #+#    #+#             */
/*   Updated: 2023/05/17 15:52:48 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	do_move(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collectables_counter != 0)
			return (0);
		printf("Bravo!!! Firulais has found all the treats, he is a happy dog now!\n");
		exit_game(game);
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->steps_counter++;
	}
	else if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->collectables_counter--;
		game->steps_counter++;
	}
	return (1);
}

static int	up_down(t_game *game, int command, int y, int x)
{
	int	move;

	if (command == 13 || command == 126)
	{
		y--;
		if (game->map[y][x] == '1')
			return (0);
		move = do_move(game, y, x);
		if (!move)
			return (0);
		game->map[y + 1][x] = '0';
	}
	else if (command == 1 || command == 125)
	{
		y++;
		if (game->map[y][x] == '1')
			return (0);
		move = do_move(game, y, x);
		if (!move)
			return (0);
		game->map[y - 1][x] = '0';
	}
	printf("Steps: %i\n", game->steps_counter);
	printf("Collectables left: %i\n", game->collectables_counter);
	return (1);
}

static int	left_right(t_game *game, int command, int y, int x)
{
	int	move;

	if (command == 0 || command == 123)
	{
		x--;
		if (game->map[y][x] == '1')
			return (0);
		move = do_move(game, y, x);
		if (!move)
			return (0);
		game->map[y][x + 1] = '0';
	}
	else if (command == 2 || command == 124)
	{
		x++;
		if (game->map[y][x] == '1')
			return (0);
		move = do_move(game, y, x);
		if (!move)
			return (0);
		game->map[y][x - 1] = '0';
	}
	printf("Steps: %i\n", game->steps_counter);
	printf("Collectables left: %i\n", game->collectables_counter);
	return (1);
}

int	controls(int command, t_game *game)
{
	int	works;
	int	x;
	int	y;

	x = game->x_axis;
	y = game->y_axis;

	if (command == 53)
		exit_game(game);
	if (command == 13 || command == 126)
		works = up_down(game, command, y, x);
	if (command == 1 || command == 125)
		works = up_down(game, command, y, x);
	if (command == 0 || command == 123)
		works = left_right(game, command, y, x);
	if (command == 2 || command == 124)
		works = left_right(game, command, y, x);
	if (works)
		add_graphics(game, 0, 0);
	return (1);
}
