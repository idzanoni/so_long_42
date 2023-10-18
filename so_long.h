/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:33:29 by izanoni           #+#    #+#             */
/*   Updated: 2023/10/18 16:36:41 by izanoni          ###   ########.fr       */
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

# define BLUEY_D "textures/bluey_down.xpm"
# define BLUEY_U "textures/bluey_up.xpm"
# define BLUEY_L "textures/bluey_left.xpm"
# define BLUEY_R "textures/bluey_right.xpm"
# define EXIT_C "textures/exit_close.xpm"
# define EXIT_O "textures/exit_open.xpm"
# define TILE "textures/tile.xpm"
# define WALL "textures/wall.xpm"
# define BALLOON "textures/balloon.xpm"
# define BACKGROUND "textures/background.xpm"

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			width;
	int			height;
	int			collect;
	int			moves;
	int			player_y;
	int			player_x;
	void		*player;
	void		*bluey_d;
	void		*bluey_l;
	void		*bluey_r;
	void		*bluey_u;
	void		*exit_c;
	void		*exit_o;
	void		*tile;
	void		*wall;
	void		*balloon;
	void		*background;
}			t_mlx;

char	**ft_read_map(char **argv);
char	**ft_dup_map(t_mlx *mlx);
int		ft_key(int tecla, t_mlx *mlx);
int		ft_matrix_len(char **matrix);
int		ft_valid_map_size(t_mlx *mlx);
int		ft_valid_map_name(int arg_c, char **arg_v);
int		ft_xpm_to_img(t_mlx *mlx, void **image, char *path);
int		ft_show_moves(t_mlx *mlx);
int		ft_close(t_mlx *mlx);
int		ft_count_line(int fd);
int		ft_check_border(t_mlx *mlx);
int		ft_valid_chars(t_mlx *mlx);
int		ft_check_map_format(t_mlx *mlx);
int		ft_check_all(t_mlx *mlx);
int		ft_count_collectibles(t_mlx *mlx);
int		ft_count_exit(t_mlx *mlx);
int		ft_count_player(t_mlx *mlx);
int		ft_key_moves(t_mlx *mlx, int sum_y, int sum_x);
int		ft_draw_map(t_mlx *mlx);
void	ft_find_player(t_mlx *mlx);
void	ft_put_sprites(t_mlx *mlx);
void	ft_struct_init(t_mlx *mlx);
void	ft_img_to_win(t_mlx *mlx, void *image, int width, int height);
void	ft_free_matrix(char **matrix);
void	ft_init_game(t_mlx *mlx);
void	ft_swap_n_to_zero(t_mlx *mlx);
void	ft_adjust_drawing(t_mlx *mlx);
void	ft_flood_fill(char **copy, int y, int x);
void	ft_flood_fill_check(char **copy, t_mlx *mlx);

#endif