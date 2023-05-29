/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affi_hand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:59:36 by kylian            #+#    #+#             */
/*   Updated: 2023/05/29 00:57:11 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

void	draw_square_line(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (j == 0)
				mlx_pixel_put(game->mlx, game->win, x + i, y + j, 0x000000);
			else if (i == 0)
				mlx_pixel_put(game->mlx, game->win, x + i, y + j, 0x000000);
			else
				mlx_pixel_put(game->mlx, game->win, x + i, y + j, color);
			j++;
		}
		j = 0;
		i++;
	}
}

void	affi_map_hand(t_game *game)
{
	int	i;
	int	line;

	i = -1;
	line = -1;
	while (++line < 269)
	{
		while (++i < 480)
		{
			draw_square_line(game, i * 4, line * 4, 0xFFFFFF);
		}
		i = -1;
	}
}

int	handle_mouse_click(int button, int x, int y, t_game *game)
{
	(void)button;
	y = y / 4;
	x = x / 4;
	if (game->map[y][x] == 0)
	{
		draw_square_line(game, x * 4, y * 4, 0x000000);
		game->map[y][x] = 1;
	}
	else
	{
		draw_square_line(game, x * 4, y * 4, 0xFFFFFF);
		game->map[y][x] = 0;
	}
	return (0);
}

int	affi_hand(t_game *game)
{
	static int	i = 0;

	if (i == 0)
	{
		i++;
		affi_map_hand(game);
	}
	mlx_do_sync(game->mlx);
	usleep(10000);
	return (0);
}
