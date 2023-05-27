/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:38:47 by kylian            #+#    #+#             */
/*   Updated: 2023/05/27 04:03:46 by kylian           ###   ########.fr       */
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
}			t_game;

int			print_error(int error_code);
int			ft_free(t_game *game);
char		*get_next_line(int fd);
int			ft_chr(char *s);
char		*ft_join(char *s1, char *s2);
void		ft_buf_cut(char *dest);
int			ft_len(char *s, int j);
int			ft_strlen(char *src);
#endif