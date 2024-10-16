/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:18:10 by kylian            #+#    #+#             */
/*   Updated: 2023/05/29 01:03:43 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

int	ft_adieux_in_the_thread(void)
{
	int	*result_ptr;

	result_ptr = malloc(sizeof(int));
	*result_ptr = 0;
	pthread_exit(result_ptr);
}

void	*thread_routine(void *temp)
{
	t_game	*game;

	game = (t_game *)temp;
	mlx_key_hook(game->win, key_hook_start, game);
	mlx_hook(game->win, 17, 1L << 17, ft_adieux_in_the_thread, NULL);
	mlx_mouse_hook(game->win, handle_mouse_click, game);
	mlx_loop_hook(game->mlx, affi_hand, game);
	mlx_loop(game->mlx);
	while (1)
		;
	return (NULL);
}

int	hand_write(t_game *game)
{
	int	result;
	int	*result_ptr;

	if (init_tab(game, "", 0) == 1)
	{
		if (init_temp_map(game) == 0)
			return (0);
		else
		{
			pthread_create(&game->tid, NULL, thread_routine, (void *)game);
			pthread_join(game->tid, (void **)&result_ptr);
			result = *result_ptr;
			free(result_ptr);
			if (result == 0)
				ft_free(game);
		}
	}
	else
		return (0);
	return (1);
}

int	key_hook_start(int keycode, t_game *game)
{
	int	*result_ptr;
	static int i = 0;

	if (keycode == 65307)
	{
		result_ptr = malloc(sizeof(int));
		*result_ptr = 1;
		pthread_exit(result_ptr);
	}
	else if (keycode == 65293)
	{
		if (i == 0)
			i++;
		else
		{
			result_ptr = malloc(sizeof(int));
			*result_ptr = 1;
			pthread_exit(result_ptr);
		}
	}
	(void)game;
	return (0);
}
