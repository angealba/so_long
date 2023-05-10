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
	while (line < game->map_height - 1)
		free(game->map[line++]);
	free(game->map);
	exit (0);
}

// void	init_struct(t_game *game)
// {
// 	game->fd = 0;
// 	game->map_height = 0;
// 	game->map_width = 0;
// 	game->p_count = 0;
// 	game->c_count = 0;
// 	game->e_count = 0;
// 	game->map = NULL;
// 	game->floor = 0;
// 	game->wall = 0;
// 	game->exit = 0;
// 	game->collectables = 0;
// 	game->mlx = 0;
// 	game->win = 0;
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
	check_map_ber(argv[1], ".ber");
	//init_struct(game);
	ft_memset(game, 0, sizeof(t_game));
	read_map(game, argv);
	check_errors(game);
	//printf("height: %d\nwidth: %d", game->map_height, game->map_width);
	//printf("mlx: %p\nwin: %p", game->mlx, game->mlx_win);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, (game->map_width * 70),
		(game->map_height * 70), "so_long");
	put_images(game);
	add_graphics(game);
	mlx_loop(game->mlx);
	system("leaks a.out");
}
