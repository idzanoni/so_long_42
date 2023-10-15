/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:41:45 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/13 16:45:13 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/keysym.h>
# include "libs/get_next_line/get_next_line.h"
# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"

# define PIXEL 64
# define ESC 65307

# define BLUEY_D "textures/bluey_down.xpm"
# define BLUEY_U "textures/bluey_up.xpm"
# define BLUEY_L "textures/bluey_left.xpm"
# define BLUEY_R "textures/bluey_right.xpm"
# define EXIT_C "textures/exit_close.xpm"
# define EXIT_O "textures/exit_open.xpm"
# define TILE "textures/tile.xpm"
# define WALL "textures/wall.xpm"
# define CACTUS "textures/cactus.xpm"
# define BALLOON "textures/balloon.xpm"
# define WIN "textures/win.xpm"

# define ERROR_0 "Invalid number of arguments"
# define ERROR_1 "Invalid extension"
# define ERROR_2 "Impossible to read the file"
# define ERROR_3 "Invalid map format"
# define ERROR_4 "Invalid border"
# define ERROR_5 "Impossible to access exit"
# define ERROR_6 "Impossible to access collectibles"
# define ERROR_7 "Invalid number of Players"
# define ERROR_8 "Invalid number of Exits"
# define ERROR_9 "Invalid number of Collectibles"
# define ERROR_10 "Map contains invalid character"
# define ERROR_11 "Empty Map"
# define ERROR_12 "Mlx error"
# define ERROR_13 "Sprites error"

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			width;
	int			height;
	void		*player;
	int			collect;
	int			moves;
	int			col;
	int			line;
	int			player_line;
	int			player_col;
	void		*bluey_d;
	void		*bluey_l;
	void		*bluey_r;
	void		*bluey_u;
	void		*exit_c;
	void		*exit_o;
	void		*tile;
	void		*wall;
	void		*cactus;
	void		*balloon;
	void		*win;
}			t_mlx;

char	**read_map(char **argv);
int		ft_key(int tecla, t_mlx *mlx);
void	ft_put_pix(t_mlx *mlx, int width, int height);
int		ft_matrix_len(char **matrix);
void	draw_map(t_mlx *mlx);
int		valid_map_size(t_mlx *mlx);
void	find_player(t_mlx *mlx);
int		valid_map_name(int arg_c, char **arg_v);
int		ft_xpm_to_img(t_mlx *mlx, void **image, char *path);
void	ft_put_sprites(t_mlx *mlx);
int		ft_show_moves(t_mlx *mlx);
void	ft_struct_init(t_mlx *mlx);
int		ft_close(t_mlx *mlx);
void	key_moves(t_mlx *mlx, int sum_y, int sum_x);
void	ft_img_to_win(t_mlx *mlx, void *image, int width, int height);
int		ft_count_line(int fd);
int		check_border(t_mlx *mlx);
int		valid_chars(t_mlx *mlx);
int		check_map_format(t_mlx *mlx);
void	ft_free_matrix(char **matrix);

#endif

// //Functions
// //Check
// int		ft_check_characters(t_mlx *window, int e, int p, int invalid);
// int		ft_check_exit(int exit, int collec);
// int		ft_check_path(char **copy, t_mlx *window);
// void	ft_print_error(char *error);
// int		ft_check_errors(t_mlx *window, char *path);
// int		ft_strncmp(const char *s1, const char *s2, size_t n);
// void	ft_test_path(char **copy, int line, int col, t_mlx *window);
// int		ft_valid_character(t_mlx *window);
// int		ft_valid_walls(t_mlx *window);

// //starting
// int		ft_count_col(char *temp);
// int		ft_count_collectibles(t_mlx *window);
// int		ft_count_lines(int fd, char *temp, t_mlx *window);
// int		ft_create_map(t_mlx *window, char *path);
// char	**ft_dup_map(t_mlx *window);
// int		ft_init_game(t_mlx *window);
// int		ft_read_map(t_mlx *window, char *path);
// int		ft_show_map(t_mlx *window);
// void	ft_struct_init(t_mlx *window);

// //events
// int		ft_event(int key, t_mlx *window);
// void	ft_event_arrow(t_mlx *window, int col, int line);
// int		ft_show_moves(t_mlx *window);

// //images
// void	ft_locate_player(t_mlx *window);
// void	ft_put_image_to_window(t_mlx *window, void *image, int x, int y);
// void	ft_put_sprites(t_mlx *window);
// void	ft_sprites(t_mlx *window, void **image, char *path);

// //ending
// int		ft_close(t_mlx *window);
// int		ft_close_and_free(int fd, char *temp);
// void	ft_free_matrix(char **matrix);
