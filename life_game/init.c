/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:06:28 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/27 18:26:51 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

int	charg_map(t_game *game, char *src)
{
	static int	line = 135;
	int			j;
	int			i;

	i = 0;
	j = 200;
	if (ft_strlen(src) > 270)
		return (print_error(ERRCODE_FILE_NUMBER));
	while (src[i] != '\n' && src[i])
	{
		if (src[i] != '0' && src[i] != '1')
			return (print_error(ERRCODE_FILE_NUMBER));
		if (src[i] == '1')
			game->map[line][j] = 1;
		j++;
		i++;
	}
	line++;
	return (1);
}

int init_temp_map(t_game *game)
{
	int	i;

	i = 0;
	game->map_temp = malloc(sizeof(int *) * 270);
	if (!game->map_temp)
	{
		ft_free_map(game);
		return (print_error(ERRCODE_MALLOC_FAIL));
	}
	while (i < 270)
	{
		game->map_temp[i] = malloc(sizeof(int) * 270);
		if (!game->map_temp[i])
		{
			while (--i >= 0)
				free(game->map_temp[i]);
			ft_free_map(game);
			return (print_error(ERRCODE_MALLOC_FAIL));
		}
		i++;
	}
	return (1);
}

int	init_map(t_game *game, char *argv)
{
	int		map_file;
	char	*src;

	map_file = open(argv, O_RDONLY);
	if (map_file == -1)
	{
		ft_free_map(game);
		return (print_error(ERRCODE_OPEN));
	}
	src = get_next_line(map_file);
	while (src)
	{
		if (charg_map(game, src) == 0)
		{
			free(src);
			return (ft_free_map(game));
		}
		free(src);
		src = get_next_line(map_file);
	}
	game->map_temp = game->map;
	return (init_temp_map(game));
}

void tab_to_zero(t_game *game)
{
	int i;
	int line;

	line = -1;
	while (++line < 270)
	{
		i = -1;
		while (++i < 270)
			game->map[line][i] = 0;
	}
}

int	init_tab(t_game *game, char *argv)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(int *) * 270);
	if (!game->map)
	{
		free(game);
		return (print_error(ERRCODE_MALLOC_FAIL));
	}
	while (i < 270)
	{
		game->map[i] = malloc(sizeof(int) * 270);
		if (!game->map[i])
		{
			while (--i >= 0)
				free(game->map[i]);
			free(game);
			return (print_error(ERRCODE_MALLOC_FAIL));
		}
		i++;
	}
	tab_to_zero(game);
	return (init_map(game, argv));
}
