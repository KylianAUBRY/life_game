/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:42:20 by kylian            #+#    #+#             */
/*   Updated: 2023/05/27 04:05:45 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_free(game);
	return (0);
}

int	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < 270)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
	return (0);
}

int	ft_free(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_map(game);
	exit(0);
	return (0);
}

int	game_boucle(t_game *game)
{
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 1L << 17, ft_free, game);
	mlx_loop(game->mlx);
	return (0);
}

void	draw_square(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			mlx_pixel_put(game->mlx, game->win, x + i, y + j, 0xFFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
}

int	charg_map(t_game *game, char *src)
{
	static int	line = 0;
	int			i;

	i = 0;
	if (ft_strlen(src) > 271)
	while (src[i] != '\n' && src[i])
	{
		if (src[i] != '0' && src[i] != '1')
			return (print_error(ERRCODE_FILE_NUMBER));
		if (src[i] == '1')
			game->map[line][i] = 1;
		i++;
	}
	line++;
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
	return (1);
}

void tab_to_zero(t_game *game)
{
	int i;
	int line;

	i = 0;
	line = -1;
	while (++line < 269)
	{
		while (++i < 269)
			game->map[line][i] = 0;
		game->map[line][i] = 2;
		i = -1;
		line++;
	}
	game->map[line] = NULL;
}

int	init_tab(t_game *game, char *argv)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(int *) * 271);
	if (!game->map)
	{
		free(game);
		return (print_error(ERRCODE_MALLOC_FAIL));
	}
	while (i < 270)
	{
		game->map[i] = malloc(sizeof(int) * 271);
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

int	main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
		return (print_error(ERRCODE_ARG));
	game = malloc(sizeof(t_game));
	if (!game)
		return (print_error(ERRCODE_MALLOC_FAIL));
	if (init_tab(game, argv[1]) == 0)
		return (0);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (print_error(ERRCODE_INIT_WIN));
	game->win = mlx_new_window(game->mlx, 1920, 1080, "The game of life");
	if (game->win == NULL)
		return (print_error(ERRCODE_CREATE_WIN));
	draw_square(game, 500, 500);
	game_boucle(game);
	(void)argc;
	(void)argv;
}