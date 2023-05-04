/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:02:59 by analbarr          #+#    #+#             */
/*   Updated: 2023/04/20 16:04:11 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

// int	exit_game(t_game *game)
// {
// 	int	line;

// 	line = 0;
// 	if (game->mlx_win)
// 		mlx_destroy_window(game->mlx, game->mlx_win);
// 	free(game->mlx);
// 	while (line < game->map_height - 1)
// 		free(game->map[line++]);
// 	free(game->map);
// 	exit (0);
// }

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		printf("Error in the number of arguments\n");
		return (0);
	}
	game = (t_game *)malloc(sizeof(t_game));
	check_map_ext(argv[1], ".ber");
	ft_memset(game, 0, sizeof(t_game));
	read_map(game, argv);
	check_rectangle(game);
	printf("height: %d\nwidth: %d", game->map_height, game->map_width);
	// game->mlx = mlx_init();
	// game->mlx_win = mlx_new_window(game->mlx, 960, 540, "hello");
	// mlx_loop(game->mlx);
	return (0);
}