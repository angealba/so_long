/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:53:50 by analbarr          #+#    #+#             */
/*   Updated: 2023/05/10 19:54:11 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_player(t_game *game, int img_h, int img_w)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player,
		img_w * 70, img_h * 70);
	game->y_axis = img_h;
	game->x_axis = img_w;
}

static void	put_collectables(t_game *game, int img_h, int img_w)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectable,
		img_w * 70, img_h * 70);
	game->collectables_counter++;
}

void	add_graphics(t_game *game, int img_w, int img_h)
{
	game->collectables_counter = 0;
	while (img_h < game->map_height)
	{
		img_w = 0;
		while (game->map[img_h][img_w])
		{
			if (game->map[img_h][img_w] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->floor, img_w * 70, img_h * 70);
			if (game->map[img_h][img_w] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->wall, img_w * 70, img_h * 70);
			if (game->map[img_h][img_w] == 'P')
				put_player(game, img_h, img_w);
			if (game->map[img_h][img_w] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->exit, img_w * 70, img_h * 70);
			if (game->map[img_h][img_w] == 'C')
				put_collectables(game, img_h, img_w);
			img_w++;
		}
		img_h++;
	}
}

void	add_images(t_game *game)
{
	int	img_w;
	int	img_h;

	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/grass.xpm",
			&img_w, &img_h);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/tree.xpm",
			&img_w, &img_h);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/dog.xpm",
			&img_w, &img_h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/house.xpm",
			&img_w, &img_h);
	game->collectable = mlx_xpm_file_to_image(game->mlx, "textures/bone.xpm",
			&img_w, &img_h);
	add_graphics(game, 0, 0);
}
