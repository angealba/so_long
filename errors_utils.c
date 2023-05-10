/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:27:37 by analbarr          #+#    #+#             */
/*   Updated: 2023/05/05 17:27:58 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	char_count(t_game *game, int h, int w)
{
	if (game->map[h][w] != '1' && game->map[h][w] != '0'
		&& game->map[h][w] != 'P' && game->map[h][w] != 'C'
		&& game->map[h][w] != 'E' && game->map[h][w] != '\n')
	{
		printf("Error: Unknown map components\n");
		exit_game(game);
	}
	if (game->map[h][w] == 'C')
		game->c_count++;
	if (game->map[h][w] == 'P')
		game->p_count++;
	if (game->map[h][w] == 'E')
		game->e_count++;
}

void	valid_char(t_game *game)
{
	int	w;
	int	h;

	h = 0;
	while (h < game->map_height - 1)
	{
		w = 0;
		while (w <= game->map_width)
		{
			char_count(game, h, w);
			w++;
		}
		h++;
	}
	if (!(game->p_count == 1 && game->e_count == 1 && game->c_count >= 1))
	{
		printf("Error: Player, exit or collectable number is wrong.\n");
		exit_game(game);
	}
}

void	copy_map(char **cpy, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
		cpy[i] = (char *)malloc(sizeof(char) * game->map_width);
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
			cpy[i][j] = game->map[i][j];
	}
}
