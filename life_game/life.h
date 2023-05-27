/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:38:47 by kylian            #+#    #+#             */
/*   Updated: 2023/05/27 16:01:40 by kyaubry          ###   ########.fr       */
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
# include <unistd.h>

# define ERRCODE_MALLOC_FAIL 1
# define ERRCODE_INIT_WIN 2
# define ERRCODE_CREATE_WIN 3
# define ERRCODE_ARG 4
# define ERRCODE_FILE_NUMBER 5
# define ERRCODE_OPEN 6

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		**map;
	int		**map_temp;
}			t_game;

int			print_error(int error_code);
int			ft_free(t_game *game);
char		*get_next_line(int fd);
int			ft_chr(char *s);
char		*ft_join(char *s1, char *s2);
void		ft_buf_cut(char *dest);
int			ft_len(char *s, int j);
int			ft_strlen(char *src);
int			init_tab(t_game *game, char *argv);
void		tab_to_zero(t_game *game);
int			init_map(t_game *game, char *argv);
int			charg_map(t_game *game, char *src);
int			ft_free_map(t_game *game);
int			ft_free(t_game *game);
void		draw_square(t_game *game, int x, int y);
int			game_boucle(t_game *game);
int			affi_game(t_game *game);
void		affi_map(t_game *game);

#endif