/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:01:37 by analbarr          #+#    #+#             */
/*   Updated: 2023/05/03 21:01:56 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_walls_lenght(t_game *game)
{
	int	w;
	int	i;

	i = 1;
	while (game->map[i])
	{
		w = get_width(game->map[i]);
		if (w != game->map_width)
		{
			printf("Error: Map lines don't have the same lenght.\n");
			exit (0);
		}
		i++;
	}
}

static int	horizontal_wall(t_game *game)
{
	int	w;

	w = 0;
	while (w < game->map_width)
	{
		if (!(game->map[0][w] == '1' && game->map[game->map_height -1][w] == '1'))
			return (0);	
		w++;		
	}
	return (1);
}

static int	vertical_wall(t_game *game)
{
	int h;

	h = 0;
	while (h < game->map_height)
	{
		if (!(game->map[h][0] == '1' && game->map[h][game->map_width - 1] == '1'))
			return (0);
		h++;
	}
	return (1);
}

void	check_errors(t_game *game)
{
	int		hor_wall;
	int		ver_wall;
	char	**cpy;

	check_walls_lenght(game);
	hor_wall = horizontal_wall(game);
	ver_wall = vertical_wall(game);
	if (hor_wall == 0 || ver_wall == 0)
	{
		printf("Error: Map is not completely closed.\n");
		exit_game(game);
	}
	valid_char(game);
	printf("C: %d\nE: %d\nP: %d\n", game->c_count, game->e_count, game->p_count);
	cpy = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	copy_map(cpy, game);
	check_route(cpy, game);


}