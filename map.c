/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:40:15 by analbarr          #+#    #+#             */
/*   Updated: 2023/04/26 19:41:03 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_ber(char *map, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(map) - ft_strlen(ext);
	j = 0;
	while (map[i + j] != '\0' && ext[j] != '\0')
	{
		if (map[i + j] == ext[j])
			j++;
		else
		{
			printf("Error: map is not a .ber file\n");
			exit(1);
		}
	}
}

static int	add_line(t_game *game, char *line)
{
	char	**tmp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->map_height++;
	tmp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!tmp)
		return (0);
	tmp[game->map_height] = NULL;
	while (i < game->map_height - 1)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = line;
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (1);
}

int	get_width(char *str)
{
	int	w;

	w = 0;
	while (str[w] != '\0')
		w++;
	if (str[w - 1] == '\n')
		w--;
	return (w);
}

int	read_map(t_game *game, char **argv)
{
	char	*line;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		printf("Error in opening the map\n");
		exit_game(game);
	}
	while (1)
	{
		line = get_next_line(game->fd);
		if (!add_line(game, line))
			break ;
	}
	if (game->map_height == 0 && game->map_width == 0)
	{
		printf("Error: Empty map\n");
		exit_game (game);
	}
	game->map_width = get_width(game->map[0]);
	close (game->fd);
	return (1);
}
