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

void	check_rectangle(t_game *game)
{
	int	w;
	int	i;

	i = 1;
	while (game->map[i])
	{
		w = get_width(game->map[i]);
		if (w != game->map_width)
		{
			printf("Error: Map lines don't have the same lenght\n");
			exit_game(game);
		}
		i++;
	}
}
