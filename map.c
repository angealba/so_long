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

void	check_map(char *map, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(map) - ft_strlen(ext);
	j = 0;
	while(map[i + j] != '\0' && ext[j] != '\0')
	{
		if(map[i + j] == ext[j])
			j++;
		else
		{
			printf("Error: map is not a .ber file\n");
			exit(1);
		}
	}
}

int read_map(t_game *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		printf("Error in opening the map\n");
		return (0);
	}
	while (1)
	{
		readmap = get_next_line(game->fd);
		if(!add_line(game, reading))
			break ;
	}
	close (game->fd);
	return (1);

}
