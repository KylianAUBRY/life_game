/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:07:59 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/29 00:36:47 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

int ft_free_hand(t_game *game)
{
	ft_free_map_temp(game);
	ft_free_map(game);
	exit(0);
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

int ft_free_map_temp(t_game *game)
{
	int	i;

	i = 0;
	while (i < 270)
	{
		free(game->map_temp[i]);
		i++;
	}
	free(game->map_temp);
	return (0);
}

int	ft_free(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_map_temp(game);
	ft_free_map(game);
	exit(0);
	return (0);
}

int ft_free_mlx(t_game *game)
{
	print_error(ERRCODE_INIT_WIN);
	ft_free_map_temp(game);
	ft_free_map(game);
	exit(0);
	return (0);
}

int ft_free_window(t_game *game)
{
	print_error(ERRCODE_CREATE_WIN);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_map_temp(game);
	ft_free_map(game);
	exit(0);
	return (0);
}
