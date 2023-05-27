/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:42:20 by kylian            #+#    #+#             */
/*   Updated: 2023/05/27 18:45:39 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_free(game);
	return (0);
}

int	verif_cel(t_game *game, int i, int line)
{
	int	count;

	count = 0;
	if (i != 0)
	{
		count += game->map[line][i - 1];
		if (line != 0)
			count += game->map[line - 1][i - 1];
		if (line < 268)
			count += game->map[line + 1][i - 1];
	}
	if (i < 268)
	{
		count += game->map[line][i + 1];
		if (line != 0)
			count += game->map[line - 1][i + 1];
		if (line < 268)
			count += game->map[line + 1][i + 1];
	}
	if (line != 0)
		count += game->map[line - 1][i];
	if (line < 268)
		count += game->map[line + 1][i];
	return (count);
}

int	new_state(t_game *game, int i, int line)
{
	int	count;

	count = 0;
	count = verif_cel(game, i, line);
	if (game->map[line][i] == 1)
	{
		if (count != 3 && count != 2)
			return (0);
		else
			return (1);
	}
	else
	{
		if (count != 3)
			return (0);
		else
			return (1);
	}
}

int	char_temp_map(t_game *game)
{
	int	i;
	int	line;

	line = -1;
	while (++line < 269)
	{
		i = -1;
		while (++i < 269)
		{
			game->map_temp[line][i] = new_state(game, i, line);
		}
	}
	line = -1;
	while (++line < 269)
	{
		i = -1;
		while (++i < 269)
		{
			game->map[line][i] = game->map_temp[line][i];
		}
	}	
	return (0);
}

void	affi_map(t_game *game)
{
	int	i;
	int	line;

	i = -1;
	line = -1;
	while (++line < 269)
	{
		while (++i < 269)
		{
			if (game->map[line][i] == 1)
				draw_square(game, i * 4, line * 4);
		}
		i = -1;
	}
}

int	affi_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	affi_map(game);
	char_temp_map(game);
	mlx_do_sync(game->mlx);
	usleep(10000);
	return (0);
}

int	game_boucle(t_game *game)
{
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 1L << 17, ft_free, game);
	mlx_loop_hook(game->mlx, affi_game, game);
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
	game_boucle(game);
	(void)argc;
	(void)argv;
}