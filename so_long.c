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
#include <mlx.h>

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

int	exit_game(t_game *game)
{
	int	line;

	line = 0;
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	while (line < game->map_height)
		free(game->map[line++]);
	free(game->map);
	exit (0);
}

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	atexit(leaks);
	if (argc != 2)
	{
		printf("Error in the number of arguments\n");
		return (0);
	}
	game = (t_game *)malloc(sizeof(t_game));
	check_map_ber(argv[1], ".ber");
	ft_memset(game, 0, sizeof(t_game));
	read_map(game, argv);
	check_errors(game);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, (game->map_width * 70),
			(game->map_height * 70), "so_long");
	add_images(game);
	mlx_key_hook(game->mlx_win, controls, game);
	mlx_hook(game->mlx_win, 17, 0, (void *)exit, 0);
	system("leaks so_long");
	mlx_loop(game->mlx);
}
