/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:38:47 by kylian            #+#    #+#             */
/*   Updated: 2023/05/28 04:11:18 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERRCODE_MALLOC_FAIL 1
# define ERRCODE_INIT_WIN 2
# define ERRCODE_CREATE_WIN 3
# define ERRCODE_ARG 4
# define ERRCODE_FILE_NUMBER 5
# define ERRCODE_OPEN 6
# define ERRCODE_PROCESSUS 7

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			time;
	int			**map;
	int			**map_temp;
	pthread_t	tid;
}				t_game;

int				print_error(int error_code);
int				ft_free(t_game *game);
char			*get_next_line(int fd);
int				ft_chr(char *s);
char			*ft_join(char *s1, char *s2);
void			ft_buf_cut(char *dest);
int				ft_len(char *s, int j);
int				ft_strlen(char *src);
int				init_tab(t_game *game, char *argv, int j);
void			tab_to_zero(t_game *game);
int				init_map(t_game *game, char *argv);
int				init_temp_map(t_game *game);
int				charg_map(t_game *game, char *src);
int				ft_free_map(t_game *game);
int				ft_free_map_temp(t_game *game);
int				ft_free(t_game *game);
int				ft_free_hand(t_game *game);
int				ft_free_mlx(t_game *game);
int				ft_free_window(t_game *game);
void			draw_square(t_game *game, int x, int y);
int				game_boucle(t_game *game);
int				affi_game(t_game *game);
void			affi_map(t_game *game);
int				key_hook_start(int keycode, t_game *game);
int				hand_write(t_game *game);
void			draw_square_line(t_game *game, int x, int y, int color);
void			affi_map_hand(t_game *game);
int				handle_mouse_click(int button, int x, int y, t_game *game);
int				affi_hand(t_game *game);
int	hand_write(t_game *game);

#endif